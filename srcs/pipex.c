/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:12:14 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/28 16:28:39 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1(char **av, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_error("error file 1 !\n");
	if (dup2(fd, STDIN_FILENO) == -1)
		exit_error("dup error !\n");
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		exit_error("dup error !\n");
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	close(fd);
	executable(av[2], env);
}

void	child_2(char **av, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		exit_error("error file 2 !\n");
	if (dup2(fd, STDOUT_FILENO) == -1)
		exit_error("dup error !\n");
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		exit_error("dup error !\n");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(fd);
	executable(av[3], env);
}

void	executable(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	if (!*cmd || !env)
		exit(-1);
	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd || !split_cmd[0])
	{
		ft_free_tab(split_cmd);
		exit_error("split error !\n");
	}
	path = get_path(split_cmd, env);
	if (path == NULL)
	{
		ft_free_tab(split_cmd);
		exit_error("path error !\n");
	}
	if (execve(path, split_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found : 2", 2);
		ft_putstr_fd(split_cmd[0], 2);
		write(2, "\n", 1);
		ft_free_tab(split_cmd);
		exit(1);
	}
}

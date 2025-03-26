/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:12:14 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/26 15:25:27 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1(char **av, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		exit_error("missing file 1 !\n");
		exit(0);
	}
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

	fd = open(av[4], O_WRONLY | O_CREAT);
	if (fd == -1)
	{
		exit_error("missing file 2 !\n");
		exit(1);
	}
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

	if (!*cmd)
		exit(1);
	split_cmd = ft_split(cmd, ' ');
	if (split_cmd == NULL)
	{
		exit_error("split error !\n");
		return ;
	}
	path = get_path(split_cmd[0], env);
	if (path == NULL)
	{
		exit_error("path error !\n");
		ft_free_tab(split_cmd);
		return ;
	}
	if (execve(path, split_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(split_cmd[0], 2);
		ft_free_tab(split_cmd);
		exit(1);
	}
}

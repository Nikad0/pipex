/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:12:14 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/14 15:26:34 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_child(pid_t pid_1, pid_t pid_2)
{
	int	status;

	status = 0;
	waitpid(pid_1, &status, 0);
	waitpid(pid_2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (127 + WTERMSIG(status));
	return (EXIT_SUCCESS);
}

void	child_1(char **av, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		close_error(pipe_fd);
		exit_error("error file 1 !\n");
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

	fd = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		close_error(pipe_fd);
		exit_error("error file 2 !\n");
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
		exit_error("dup error !\n");
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		exit_error("dup error !\n");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(fd);
	executable(av[3], env);
	exit(127);
}

void	executable(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	if (!*cmd || !env)
		exit(0);
	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd || !split_cmd[0])
	{
		ft_free_tab(split_cmd);
		exit_error("split error !\n");
		exit(0);
	}
	path = get_path(split_cmd, env);
	if (path == NULL)
	{
		ft_free_tab(split_cmd);
		exit_error("path error !\n");
		exit(127);
	}
	if (execve(path, split_cmd, env) == -1)
	{
		ft_putstr_fd("Error : command not found !\n", 2);
		ft_free_tab(split_cmd);
		free(path);
	}
}

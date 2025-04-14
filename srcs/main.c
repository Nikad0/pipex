/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:29:07 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/14 15:29:41 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(char *exit_msg)
{
	write(2, exit_msg, ft_strlen(exit_msg));
	exit(127);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	all_path_not_found(char **path, char **split_cmd)
{
	ft_putstr_fd("Error : command not found : ", 2);
	ft_putstr_fd(split_cmd[0], 2);
	write(2, "\n", 1);
	ft_free_tab(split_cmd);
	ft_free_tab(path);
	exit(127);
}

void	close_error(int *fd)
{
	if (fd)
	{
		close(fd[1]);
		close(fd[0]);
	}
	return ;
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;

	if (argc != 5)
		exit_error("error : wrong number of argument given !\n");
	if (pipe(pipe_fd) == -1)
		exit_error("pipe error !\n");
	pid_1 = fork();
	if (pid_1 == -1)
		close_error(pipe_fd);
	if (pid_1 == 0)
		child_1(argv, pipe_fd, env);
	pid_2 = fork();
	if (pid_2 == -1)
		close_error(pipe_fd);
	if (pid_2 == 0)
		child_2(argv, pipe_fd, env);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (wait_child(pid_1, pid_2));
}

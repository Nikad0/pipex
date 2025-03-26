/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:29:07 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/26 14:49:20 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_error(char *exit_msg)
{
	write(2, exit_msg, ft_strlen(exit_msg));
	return (EXIT_FAILURE);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	all_path_not_found(char **allpath, char *cmd)
{
	ft_free_tab(allpath);
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	int		status;
	pid_t	pid_1;
	pid_t	pid_2;

	status = 0;
	if (argc != 5)
		exit_error("wrong number of argument given !\n");
	if (pipe(pipe_fd) == -1)
		exit_error("pipe error !\n");
	pid_1 = fork();
	if (pid_1 == -1)
		exit_error("fork error !\n");
	if (pid_1 == 0)
		child_1(argv, pipe_fd, env);
	pid_2 = fork();
	if (pid_2 == -1)
		exit_error("fork error !\n");
	if (pid_2 == 0)
		child_2(argv, pipe_fd, env);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid_1, &status, 0);
	waitpid(pid_2, &status, 0);
	return (status);
}

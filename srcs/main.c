/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:29:07 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/21 17:43:20 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_error(int n_exit)
{
	if (n_exit == 1)
	{
		ft_putstr_fd("incorrect number of argument !\n", 2);
		exit(1);
	}
	if (n_exit == 2)
		perror("pipe");
	if (n_exit == 3)
		perror("fork");
	if (n_exit == 4)
		perror("dup2 child");
	if (n_exit == 5)
		perror("dup2 parent");
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
	pid_t	pid;

	if (argc != 5)
		exit_error(1);
	pipe(pipe_fd);
	if (*pipe_fd == -1)
		exit_error(2);
	pid = fork();
	if (pid == -1)
		exit_error(3);
	if (!pid)
		child(argv, pipe_fd, env);
	parent(argv, pipe_fd, env);
}

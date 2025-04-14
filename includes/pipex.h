/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:23:19 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/14 15:18:42 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// main.c //
void	close_error(int *fd);
void	ft_free_tab(char **tab);
void	exit_error(char *exit_msg);
void	all_path_not_found(char **allpath, char **split_cmd);

// pipex.c //
int		wait_child(pid_t pid_1, pid_t pid_2);
void	child_1(char **av, int *pipe_fd, char **env);
void	child_2(char **av, int *pipe_fd, char **env);
void	executable(char *cmd, char **env);

// getters.c //
char	*my_getenv(char *name, char **env);
char	*get_path(char **split_cmd, char **env);

#endif
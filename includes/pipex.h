/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:23:19 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/26 17:02:46 by erbuffet         ###   ########lyon.fr   */
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
void	ft_free_tab(char **tab);
void	exit_error(char *exit_msg);
void	all_path_not_found(char **allpath, char *cmd);

// pipex.c //
void	child_1(char **av, int *pipe_fd, char **env);
void	child_2(char **av, int *pipe_fd, char **env);
void	executable(char *cmd, char **env);

// getters.c //
char	*my_getenv(char *name, char **env);
char	*get_path(char *cmd, char **env);

#endif
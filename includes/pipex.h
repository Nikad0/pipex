/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:23:19 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/26 14:41:15 by erbuffet         ###   ########lyon.fr   */
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

void	child_1(char **av, int *pipe_fd, char **env);
void	child_2(char **av, int *pipe_fd, char **env);
void	executable(char *cmd, char **env);
char	*my_getenv(char *name, char **env);
char	*get_path(char *cmd, char **env);
void	all_path_not_found(char **allpath, char *cmd);
void	ft_free_tab(char **tab);
int		exit_error(char *exit_msg);

#endif
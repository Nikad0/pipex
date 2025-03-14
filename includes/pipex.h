/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:23:19 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/13 01:43:16 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

int		exit_error(int n_exit);
void	ft_free_tab(char **tab);
void	child(char **av, int *p_fd, char **env);
void	exec(char *cmd, char **env);
char	*my_getenv(char *name, char **env);
char	*get_path(char *cmd, char **env);
void	parent(char **av, int *p_fd, char **env);

#endif
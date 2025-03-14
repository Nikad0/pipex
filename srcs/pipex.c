/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:12:14 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/13 02:33:57 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("missing file 1 !\n", 1);
		exit(0);
	}
	if (dup2(fd, 0) < 0)
		exit_error(4);
	if (dup2(pipe_fd[1], 1) < 0)
		exit_error(4);
	close(pipe_fd[0]);
	close(fd);
	exec(argv[2], env);
}

void	parent(char **argv, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd < 0)
	{
		ft_putstr_fd("missing file 2 !\n", 1);
		exit(1);
	}
	if (dup2(fd, 1) < 0)
		exit_error(5);
	if (dup2(pipe_fd[0], 0) < 0)
		exit_error(5);
	close(pipe_fd[1]);
	close(fd);
	exec(argv[3], env);
}

void	exec(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	if (!*cmd)
		exit(1);
	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd || !split_cmd[0])
		exit_error(1);
	path = get_path(split_cmd[0], env);
	if (execve(path, split_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(split_cmd[0], 2);
		ft_free_tab(split_cmd);
		exit(1);
	}
}

char	*my_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	*path_part;
	char	**allpath;

	i = -1;
	allpath = ft_split(my_getenv("PATH", env), ':');
	if (!allpath)
		exit_error(1);
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(allpath);
			return (exec);
		}
		free(exec);
	}
	ft_free_tab(allpath);
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	exit(1);
}

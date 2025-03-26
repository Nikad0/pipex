/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:51:27 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/26 16:11:52 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env(char *name, char **env)
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

char	*get_exec_path(char **path, char *cmd, char *path_part, char *exec)
{
	int	i;

	i = -1;
	while (path[++i])
	{
		path_part = ft_strjoin(path[i], "/");
		if (path_part == NULL)
		{
			exit_error("path error !\n");
			return (NULL);
		}
		exec = ft_strjoin(path_part, cmd);
		if (exec == NULL)
		{
			exit_error("exec error !\n");
			free(path_part);
			return (NULL);
		}
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	all_path_not_found(path, cmd);
	exit(-1);
}

char	*get_path(char *cmd, char **env)
{
	char	**path;
	char	*exec;
	char	*path_part;

	path_part = NULL;
	exec = NULL;
	*env = get_env("PATH", env);
	if (*env == NULL)
	{
		exit_error("env error !\n");
		return (NULL);
	}
	path = ft_split(*env, ':');
	if (!path)
	{
		exit_error("path error !\n");
		return (NULL);
	}
	exec = get_exec_path(path, cmd, path_part, exec);
	ft_free_tab(path);
	return (exec);
}

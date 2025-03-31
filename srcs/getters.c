/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikado <nikado@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:51:27 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/31 16:06:50 by nikado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_error(char **split_cmd, char *part_path)
{
	ft_free_tab(split_cmd);
	free(part_path);
	exit_error("exec error !\n");
}

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

char	*get_exec_path(char **path, char **split_cmd, char *part_path,
		char *exec)
{
	int	i;

	i = -1;
	while (path[++i])
	{
		part_path = ft_strjoin(path[i], "/");
		if (part_path == NULL)
		{
			exit_error("path error !\n");
			return (NULL);
		}
		exec = ft_strjoin(part_path, split_cmd[0]);
		if (exec == NULL)
		{
			exec_error(split_cmd, part_path);
			return (NULL);
		}
		free(part_path);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	all_path_not_found(path, split_cmd);
	exit(-1);
}

char	*get_path(char **split_cmd, char **env)
{
	char	**path;
	char	*part_path;
	char	*part_env;
	char	*exec;

	part_path = NULL;
	exec = NULL;
	part_env = get_env("PATH", env);
	if (part_env == NULL)
		return (NULL);
	path = ft_split(part_env, ':');
	if (!path && !path[0])
	{
		free(part_env);
		ft_free_tab(path);
		ft_free_tab(split_cmd);
		exit_error("getting_path error !\n");
	}
	exec = get_exec_path(path, split_cmd, part_path, exec);
	ft_free_tab(path);
	return (exec);
}

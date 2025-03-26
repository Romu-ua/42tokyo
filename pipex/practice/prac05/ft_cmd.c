/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:23:29 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/25 20:23:30 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char **envp)
{
	int		i;

	i = 0;
	while (1)
	{
		if (!envp[i])
			return (NULL);
		if (!ft_strncmp(envp[i], "PATH", 4))
			break ;
		i++;
	}
	return (envp[i] + 5);
}

void	*find_cmd(char *cmd, char **envp)
{
	int		i;
	char	**split;
	char	*file;
	char	*path;

	path = find_path(envp);
	if (!path)
		return (NULL);
	split = ft_split(path, ':');
	cmd = ft_strjoin("/", cmd);
	i = 0;
	while (1)
	{
		if (!split[i])
			return (NULL);
		file = ft_strjoin(split[i], cmd);
		if (access(file, F_OK) != -1)
			return (file);
		i++;
	}
	return (NULL);
}

char	*ft_cmd(char *arg, char **envp)
{
	char	*cmd;

	if (access(arg, X_OK) != -1)
		cmd = arg;
	else
	{
		cmd = find_cmd(arg, envp);
		if (!cmd)
			return (NULL);
	}
	return (cmd);
}

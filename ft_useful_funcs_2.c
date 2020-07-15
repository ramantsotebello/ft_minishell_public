/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful_funcs_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:53:43 by tramants          #+#    #+#             */
/*   Updated: 2018/09/21 12:50:33 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int		ft_isin_array(char *cmd, char **allowed_cmds)
{
	int		i;
	int		array_max_size;

	i = 0;
	array_max_size = ft_get_matrix_size(allowed_cmds);
	if (cmd[0] == '\0' || cmd == NULL)
		return (0);
	while (i < array_max_size)
	{
		if ((ft_strcmp(allowed_cmds[i], cmd)) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_full_path(char **env)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			path = ft_strdup(env[i]);
			return (path);
		}
		i++;
	}
	return (path);
}

char	**ft_get_split_path(char *full_path)
{
	char **split_path;

	split_path = ft_strsplit(full_path, ':');
	return (split_path);
}

int		ft_search_dir(DIR *dir, struct dirent *dir_info, char *cmd)
{
	while ((dir_info = readdir(dir)) != NULL)
	{
		if ((ft_strcmp(dir_info->d_name, cmd)) == 0)
			return (1);
	}
	return (0);
}

int		ft_isin_str(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

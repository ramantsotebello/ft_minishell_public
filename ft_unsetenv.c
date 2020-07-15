/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:46:05 by tramants          #+#    #+#             */
/*   Updated: 2018/09/27 18:50:33 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*ft_find_param(char *param, char **env)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strjoin(param, "=");
	while (env[i])
	{
		if (ft_str_isin_str(env[i], tmp) == 1)
		{
			free(tmp);
			return (env[i]);
		}
		i++;
	}
	free(tmp);
	return (NULL);
}

void	ft_unsetenv(char **args)
{
	char	*rm_str;
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strin_env(args[1], g_env) == 1)
	{
		rm_str = args[1];
		rm_str = ft_find_param(rm_str, g_env);
		new_env = (char **)
			malloc(sizeof(char *) * ft_get_matrix_size(g_env));
		while (g_env[i])
		{
			if (ft_strcmp(g_env[i], rm_str) != 0)
				new_env[j++] = ft_strdup(g_env[i]);
			i++;
		}
		new_env[j] = NULL;
		//ft_free_double_array(g_env);
		g_env = new_env;
		return ;
	}
	return ;
}

void	ft_handle_unsetenv_cmd(char **args)
{
	ft_unsetenv(args);
	return ;
}

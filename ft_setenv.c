/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:45:56 by tramants          #+#    #+#             */
/*   Updated: 2018/09/27 18:52:37 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_assign_new_env(char **old_env, char *str)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = (char **)malloc(sizeof(char *) * ft_get_matrix_size(old_env) + 2);
	while (old_env[i])
		new_env[j++] = ft_strdup(old_env[i++]);
	new_env[j++] = ft_strdup(str);
	new_env[j] = NULL;
	ft_free_double_array(g_env);
	g_env = new_env;
	return ;
}

void	ft_setenv(char **args)
{
	char	*str;
	char	*tmp;

	str = ft_strnew(0);
	if (ft_strin_env(args[1], g_env) != 1)
	{
		tmp = ft_strjoin(str, args[1]);
		free(str);
		str = tmp;
		tmp = ft_strjoin(str, "=");
		free(str);
		str = tmp;
		tmp = ft_strjoin(str, args[2]);
		free(str);
		ft_putendl(tmp);
		ft_assign_new_env(g_env, tmp);
		free(tmp);
		return ;
	}
	else
	{
		ft_unset_pair("PWD");
		ft_set_pair(args[1], args[2], 0);
	}
	return ;
}

void	ft_handle_setenv_cmd(char **args)
{
	ft_setenv(args);
	return ;
}

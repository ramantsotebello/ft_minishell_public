/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:45:42 by tramants          #+#    #+#             */
/*   Updated: 2018/09/26 07:47:32 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_putenv(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		write(1, env[i], ft_strlen(env[i]));
		write(1, "\n", 1);
		i++;
	}
}

void	ft_assign_env(void)
{
	extern char	**environ;
	char		**env;
	int			i;
	int			j;

	i = 0;
	j = 0;
	env = (char **)malloc(sizeof(char *) * ft_get_matrix_size(environ) + 1);
	while (environ[i])
	{
		env[j] = ft_strdup(environ[i]);
		j++;
		i++;
	}
	env[j] = NULL;
	g_env = env;
	return ;
}

char	**ft_getenv(char **environ)
{
	char		**env;
	int			i;

	i = 0;
	env = (char **)malloc(sizeof(char *) * ft_get_matrix_size(environ));
	while (environ[i])
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

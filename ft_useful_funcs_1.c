/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful_funcs_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:55:52 by tramants          #+#    #+#             */
/*   Updated: 2018/09/26 07:30:50 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int		ft_str_isin_str(char *haystack, char *str)
{
	unsigned int	i;

	while (*haystack)
	{
		i = 0;
		while (*haystack == *str)
		{
			str++;
			haystack++;
			if (*str == '\0')
				return (1);
		}
		haystack = haystack - i;
		str = str - i;
		haystack++;
	}
	return (0);
}

int		ft_get_matrix_size(char **double_array)
{
	int		i;

	i = 0;
	while (double_array[i])
		i++;
	return (i);
}

char	*ft_join_str_del(char **args, char delimiter, int start)
{
	char *str;

	str = "";
	while (args[start])
	{
		write(1, &args[start][0], 1);
		if (args[start][0] == delimiter)
			str = ft_strjoin(str, args[start]);
		start++;
		if (args[start] != '\0' &&\
			(args[start][ft_strlen(args[start])] == delimiter))
			break ;
	}
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	return (str);
}

void	ft_free_double_array(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
	return ;
}

int		ft_strin_env(char *str, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin(str, "=");
	while (env[i])
	{
		if (ft_str_isin_str(env[i], tmp) == 1)
		{
			free(tmp);
			return (1);
		}
		i++;
	}
	free(tmp);
	return (0);
}

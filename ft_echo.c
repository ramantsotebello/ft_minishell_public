/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:45:29 by tramants          #+#    #+#             */
/*   Updated: 2018/09/26 12:39:44 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_put_echo_str(char **args, char **env)
{
	int		i;
	int		status;
	char	*str;
	char	*tmp;

	i = 0;
	status = 0;
	if (ft_isin_str(args[1], '$') == 1)
	{
		tmp = ft_strsub(args[1], 1, ft_strlen(args[1]) - 1);
		str = ft_strjoin(tmp, "=");
		free(tmp);
		while (env[i])
		{
			if (ft_str_isin_str(env[i], str) == 1)
			{
				tmp = ft_strsub(env[i], ft_strlen(str),\
				(ft_strlen(env[i]) - ft_strlen(str)));
				write(1, tmp, ft_strlen(tmp));
				free(tmp);
				status = 1;
				break ;
			}
			i++;
		}
		free(str);
		if (status != 1)
			write(1, args[1], ft_strlen(args[1]));
	}
	else
		write(1, args[1], ft_strlen(args[1]));
	write(1, "\n", 1);
	return ;
}

void	ft_handle_echo_cmd(char **args, char **env)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid > 0)
	{
		wait(NULL);
		return ;
	}
	else if (child_pid == 0)
	{
		ft_put_echo_str(args, env);
		exit(0);
	}
}

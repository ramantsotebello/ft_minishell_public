/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:40:47 by tramants          #+#    #+#             */
/*   Updated: 2018/09/26 07:07:40 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	**ft_sanitize_echo_str(char **args)
{
	int				i;
	char			*str;
	char			*tmp;
	char			**ret_args;

	i = 1;
	str = ft_strnew(1);
	while (args[i])
	{
		tmp = ft_strjoin(str, args[i++]);
		free(str);
		str = tmp;
		if (args[i] != '\0')
		{
			tmp = ft_strjoin(str, " ");
			free(str);
			str = tmp;
		}
	}
	if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
	{
		str[0] = ' ';
		str[ft_strlen(str) - 1] = ' ';
		tmp = ft_strtrim(str);
		free(str);
		str = tmp;
	}
	if ((ret_args = (char **)malloc(sizeof(char **) * 3)) != NULL)
	{
		ret_args[0] = ft_strdup(args[0]);
		ret_args[1] = str;
		ret_args[2] = NULL;
	}
	return (ret_args);
}

int		ft_validate_args(char **args)
{
	char	**allowed_cmds;

	allowed_cmds = ft_init_allowed_cmds();
	if (args[0] != '\0')
	{
		if ((ft_isin_array(args[0], allowed_cmds)) == 0)
		{
			ft_putstr("minishell: command not found: ");
			ft_putendl(args[0]);
			free(allowed_cmds);
			return (1);
		}
	}
	free(allowed_cmds);
	return (2);
}

void	ft_signal_handler(int signal)
{
	(void)signal;
	ft_putstr("\n$> ");
	return ;
}

void	ft_close_shell(char **args)
{
	ft_free_double_array(args);
	exit(0);
}

void	ft_handle_getpwd_cmd(void)
{
	char	dir[1024];
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid > 0)
	{
		wait(NULL);
		return ;
	}
	else if (child_pid == 0)
	{
		getcwd(dir, sizeof(dir));
		write(1, ft_strtrim(dir), ft_strlen(dir));
		write(1, "\n", 1);
		exit(0);
	}
	return ;
}

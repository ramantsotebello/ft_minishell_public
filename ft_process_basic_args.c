/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_basic_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:46:18 by tramants          #+#    #+#             */
/*   Updated: 2018/09/27 18:32:13 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_handle_cmd_exec(char **args, char **env)
{
	char	*path;
	char	**paths;
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid > 0)
	{
		wait(NULL);
		return ;
	}
	else if (child_pid == 0)
	{
		path = ft_get_full_path(env);
		paths = ft_get_split_path(path);
		path = ft_find_cmdexe_path(args[0], paths);
		execve(path, args, env);
		return ;
	}
	return ;
}

char	*ft_find_cmdexe_path(char *cmd, char **paths)
{
	DIR				*dir;
	struct dirent	*dir_info;
	int				i;
	int				status;
	char			*path;

	i = 0;
	(void)cmd;
	while (paths[i])
	{
		dir_info = NULL;
		if ((dir = opendir(paths[i])) != NULL)
		{
			status = ft_search_dir(dir, dir_info, cmd);
			if (status == 1)
			{
				path = ft_strjoin(paths[i], "/");
				path = ft_strjoin(path, cmd);
				return (path);
			}
		}
		i++;
	}
	return (NULL);
}

void	ft_process_handler_func_1(char *cmd, char **args)
{
	char	**arguments;

	if ((ft_strcmp(cmd, "echo")) == 0)
	{
		arguments = ft_sanitize_echo_str(args);
		ft_handle_echo_cmd(arguments, g_env);
		ft_free_double_array(arguments);
	}
	else if ((ft_strcmp(cmd, "cd")) == 0)
	{
		arguments = ft_sanitize_echo_str(args);
		ft_handle_chdir_cmd(arguments);
		ft_free_double_array(arguments);
	}
	else if ((ft_strcmp(cmd, "clear")) == 0)
		write(1, "\033[H\033[J", 6);
	else if ((ft_strcmp(cmd, "pwd")) == 0)
		ft_handle_getpwd_cmd();
	else if ((ft_strcmp(cmd, "ls")) == 0)
		ft_handle_cmd_exec(args, g_env);
}

void	ft_process_handler_func_2(char *cmd, char **args)
{
	if ((ft_strcmp(cmd, "env")) == 0)
		ft_putenv(g_env);
	else if ((ft_strcmp(cmd, "setenv")) == 0)
		ft_handle_setenv_cmd(args);
	else if ((ft_strcmp(cmd, "unsetenv")) == 0)
		ft_handle_unsetenv_cmd(args);
	return ;
}

void	ft_process_args(char *cmd, char **args)
{
	char		**command_array_1;
	char		**command_array_2;

	command_array_1 = ft_strsplit("echo cd pwd ls", ' ');
	command_array_2 = ft_strsplit("env setenv unsetenv", ' ');
	if ((ft_strcmp(cmd, "exit")) == 0)
		ft_close_shell(args);
	else if ((ft_strcmp(cmd, "clear")) == 0)
		write(1, "\033[H\033[J", 6);
	else if ((ft_strcmp(cmd, "header")) == 0)
		ft_intialize_shell();
	else if (ft_isin_array(cmd, command_array_1))
		ft_process_handler_func_1(cmd, args);
	else if (ft_isin_array(cmd, command_array_2))
		ft_process_handler_func_2(cmd, args);
	ft_free_double_array(command_array_1);
	ft_free_double_array(command_array_2);
	return ;
}

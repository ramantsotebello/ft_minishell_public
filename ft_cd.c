/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:45:08 by tramants          #+#    #+#             */
/*   Updated: 2018/09/27 18:55:29 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*ft_sanitize_dirname(char *dir_name)
{
	char	*ret_dname;
	char	*tmp_dname;

	if (dir_name == NULL || dir_name[0] == '\0')
		ret_dname = ft_strchr(ft_find_param("HOME", g_env), '/');
	else if (dir_name[0] == '~')
	{
		tmp_dname = ft_strchr(ft_find_param("HOME", g_env), '/');
		ret_dname = (ft_isin_str(dir_name, '/')) ?\
		ft_strjoin(tmp_dname, ft_strchr(dir_name, '/')) :
		tmp_dname;
	}
	else
		ret_dname = dir_name;
	return (ret_dname);
}

void	ft_set_pair(char *key, char *value, int pair_exists)
{
	char	*set_args[4];

	if (pair_exists)
		ft_unset_pair(key);
	set_args[0] = "setenv";
	set_args[1] = key;
	set_args[2] = value;
	set_args[3] = NULL;
	ft_setenv(set_args);
	return ;
}

void	ft_unset_pair(char *key)
{
	char	*unset_args[3];

	unset_args[0] = "unsetenv";
	unset_args[1] = key;
	unset_args[2] = NULL;
	ft_unsetenv(unset_args);
	return ;
}

void	ft_handle_chdir_cmd(char **args)
{
	char	*target_dir;
	char	dir[1024];

	target_dir = ft_sanitize_dirname(args[1]);
	getcwd(dir, sizeof(dir));
	if (chdir(target_dir) != 0)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(target_dir);
	}
	else
	{
		(ft_find_param("OLDPWD", g_env) == NULL) ?\
		ft_set_pair("OLDPWD", dir, 0) : ft_set_pair("OLDPWD", dir, 1);
		getcwd(dir, sizeof(dir));
		(ft_find_param("PWD", g_env) == NULL) ?\
		ft_set_pair("PWD", dir, 0) : ft_set_pair("PWD", dir, 1);
	}
	return ;
}

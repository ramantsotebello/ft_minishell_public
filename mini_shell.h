/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:51:30 by tramants          #+#    #+#             */
/*   Updated: 2018/09/27 18:48:40 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_SHELL_H
# define FT_MINI_SHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <sys/stat.h>
# include "get_next_line.h"

int			ft_validate_args(char **args);
int			ft_isin_array(char *cmd, char **allowed_cmds);
int			ft_isin_str(char *str, char c);
int			ft_str_isin_str(char *haystack, char *str);
int			ft_get_matrix_size(char **double_array);
int			ft_strin_env(char *str, char **env);
int			ft_search_dir(DIR *dir, struct dirent *dir_info, char *cmd);
void		ft_intialize_shell(void);
void		ft_signal_handler(int signal);
void		ft_free_double_array(char **env);
void		ft_handle_autocomplete(char **str);
void		ft_put_echo_str(char **args, char **env);
void		ft_putenv(char **env);
void		ft_handle_chdir_cmd(char **args);
void		ft_handle_echo_cmd(char **args, char **env);
void		ft_handle_cmd_exec(char **args, char **env);
void		ft_handle_getpwd_cmd(void);
void		ft_handle_getpwd_cmd(void);
void		ft_close_shell(char **args);
void		ft_assign_env(void);
void		ft_handle_setenv_cmd(char **args);
void		ft_handle_unsetenv_cmd(char **args);
void		ft_process_args(char *cmd, char **args);
void		ft_setenv(char **args);
void		ft_set_pair(char *key, char *value, int pair_exists);
void		ft_unset_pair(char *key);
void		ft_unsetenv(char **args);
char		**ft_init_allowed_cmds(void);
char		*ft_get_full_path(char **env);
char		**ft_get_split_path(char *full_path);
char		*ft_find_cmdexe_path(char *cmd, char **paths);
char		*ft_get_full_path(char **env);
char		**ft_sanitize_echo_str(char **args);
char		*ft_join_str_del(char **args, char delimiter, int start);
char		*ft_find_param(char *param, char **env);
char		**ft_getenv(char **environ);
char        **g_env;
#endif

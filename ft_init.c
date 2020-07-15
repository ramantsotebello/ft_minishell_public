/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:24:45 by tramants          #+#    #+#             */
/*   Updated: 2018/09/25 16:50:02 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_intialize_shell(void)
{
	write(1, "\033[H\033[J", 6);
	write(1, "/* ************************************************* */\n", 56);
	write(1, "/*                                                   */\n", 56);
	write(1, "/*  TEBELLO                      :::      ::::::::   */\n", 56);
	write(1, "/*  RAMANTSO                   :+:      :+:    :+:   */\n", 56);
	write(1, "/*  ----------------         +:+ +:+         +:+     */\n", 56);
	write(1, "/*  MINI SHELL  v0.1       +#+  +:+       +#+        */\n", 56);
	write(1, "/*                       +#+#+#+#+#+   +#+           */\n", 56);
	write(1, "/*                             #+#    #+#            */\n", 56);
	write(1, "/*                            ###   ########.fr      */\n", 56);
	write(1, "/*  use at own risk!                                 */\n", 56);
	write(1, "/* ************************************************* */\n", 56);
	write(1, "\n\n", 2);
	write(1, "-------------------------------------------------------\n", 56);
}

char	**ft_init_allowed_cmds(void)
{
	char	**allowed_cmds;

	allowed_cmds = (char **)ft_memalloc(sizeof(char *) * 12);
	allowed_cmds[0] = "cd";
	allowed_cmds[1] = "echo";
	allowed_cmds[2] = "env";
	allowed_cmds[3] = "setenv";
	allowed_cmds[4] = "exit";
	allowed_cmds[5] = "unsetenv";
	allowed_cmds[6] = "ls";
	allowed_cmds[7] = "clear";
	allowed_cmds[8] = "pwd";
	allowed_cmds[9] = "cat";
	allowed_cmds[10] = "header";
	allowed_cmds[11] = NULL;
	return (allowed_cmds);
}

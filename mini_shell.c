/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:52:54 by tramants          #+#    #+#             */
/*   Updated: 2018/09/27 18:27:45 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int		main(void)
{
	char		*user_input_buf;
	char		**arguments;

	ft_assign_env();
	ft_intialize_shell();
	signal(SIGINT, ft_signal_handler);
	while (write(1, "$> ", 3))
	{
		if (get_next_line(0, &user_input_buf))
		{
			if (!(user_input_buf[0] == '\0') && !(!user_input_buf))
			{
				arguments = ft_strsplit(user_input_buf, ' ');
				if ((ft_validate_args(arguments)) == 2)
					ft_process_args(arguments[0], arguments);
				ft_free_double_array(arguments);
			}
		}
		else
			write(1, "$> error occured\n", 17);
		free(user_input_buf);
	}
	ft_free_double_array(g_env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful_funcs_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:47:41 by tramants          #+#    #+#             */
/*   Updated: 2018/09/26 12:38:04 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"
#include <stdarg.h>

char    **ft_init_array(int num, const char *format, ...)
{
	int			i;
	va_list		args;
	char		**ret_array;

	i = -1;
	ret_array = (char *)
	va_start(args, format);
	while (++i < num)
		ret_array[i] = va_arg(args, char *);
	ret_array[i] = NULL;
	return (ret_array);
}
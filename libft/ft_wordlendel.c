/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlendel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:18:58 by tramants          #+#    #+#             */
/*   Updated: 2018/06/19 08:12:33 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordlendel(const char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] == c)
		i++;
	while ((str[i] != c) && (str[i] != '\0'))
	{
		count++;
		i++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcountdel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:18:22 by tramants          #+#    #+#             */
/*   Updated: 2018/06/19 08:24:27 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcountdel(char const *str, char c)
{
	int		i;
	int 	count;

	i = 	0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if ((str[i] != '\0') && (str[i] != c))
			count++;
		while ((str[i] != c) && (str[i] != '\0'))
			i++;
	}
	return (count);
}

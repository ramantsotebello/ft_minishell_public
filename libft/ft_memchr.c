/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:57:21 by tramants          #+#    #+#             */
/*   Updated: 2018/06/14 06:53:23 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	letter;

	i = 0;
	str = (char *)s;
	letter = (char)c;
	while (i < n)
	{
		if (str[i] == letter)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:58:53 by tramants          #+#    #+#             */
/*   Updated: 2018/06/14 07:07:59 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t len;
	size_t count;

	len = 0;
	count = 0;
	while (s1[len] != '\0')
		len++;
	i = 0;
	while (s2[i] != '\0')
	{
		if (count >= n)
		{
			s1[len] = '\0';
			return (s1);
		}
		s1[len] = s2[i];
		i++;
		len++;
		count++;
	}
	s1[len] = '\0';
	return (s1);
}

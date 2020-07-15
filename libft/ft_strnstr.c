/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:48:49 by tramants          #+#    #+#             */
/*   Updated: 2018/06/18 13:41:52 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, const char *needle, size_t len)
{
	int			i;
	const char	*count;

	count = haystack + len;
	if (!*needle)
		return ((char *)haystack);
	while ((*haystack) && (haystack < count))
	{
		i = 0;
		while ((*haystack == *needle) && (haystack < count))
		{
			needle++;
			haystack++;
			i++;
			if (!*needle)
				return ((char *)(haystack - i));
		}
		haystack = haystack - i;
		needle = needle - i;
		haystack++;
	}
	return (NULL);
}

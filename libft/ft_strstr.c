/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:58:04 by tramants          #+#    #+#             */
/*   Updated: 2018/06/19 08:36:41 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		while (*haystack == *needle)
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

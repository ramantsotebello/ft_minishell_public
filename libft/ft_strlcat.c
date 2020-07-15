/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:08:37 by tramants          #+#    #+#             */
/*   Updated: 2018/06/18 13:58:37 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	num;
	size_t	len;

	num = dstsize + ft_strlen(src);
	len = 0;
	while (*dst && dstsize > 0)
	{
		dst++;
		dstsize--;
		len++;
	}
	if (dstsize < 1)
		return (num);
	while (*src && --dstsize > 0)
	{
		*dst++ = *src++;
		len++;
	}
	while (*src++)
		len++;
	*dst = '\0';
	return (len);
}

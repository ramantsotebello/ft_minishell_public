/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:44:54 by tramants          #+#    #+#             */
/*   Updated: 2018/06/18 13:55:09 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src_str;
	char	*dst_str;

	src_str = (char *)src;
	dst_str = (char *)dst;
	if (src_str < dst_str)
	{
		while (len--)
			dst_str[len] = src_str[len];
	}
	else
		ft_memcpy(dst_str, src_str, len);
	return (dst_str);
}

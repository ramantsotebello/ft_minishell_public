/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:28:32 by tramants          #+#    #+#             */
/*   Updated: 2018/06/14 06:59:39 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*dup_str;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
	{
		len++;
	}
	dup_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		dup_str[i] = s1[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}

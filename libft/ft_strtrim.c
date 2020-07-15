/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:57:54 by tramants          #+#    #+#             */
/*   Updated: 2018/09/21 08:36:48 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	int		count;
	char	*fresh;

	if (!s || !(*s))
		return (NULL);
	i = 0;
	while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
		i++;
	if (i > (len = ft_strlen(s) - 1))
	{
		fresh = (char *)malloc(sizeof(char) * 2);
		return ((fresh = ""));
	}
	while ((s[len] == ' ') || (s[len] == '\t') || (s[len] == '\n'))
		len--;
	count = len - i;
	if (!(fresh = ft_strnew(count + 1)))
		return (NULL);
	count = 0;
	while (i < (len + 1))
		fresh[count++] = s[i++];
	fresh[count] = '\0';
	return (fresh);
}

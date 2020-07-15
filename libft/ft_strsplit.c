/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:34:24 by tramants          #+#    #+#             */
/*   Updated: 2018/09/20 13:54:04 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		word;
	int		s_char;
	int		w_char;

	if (!s)
		return (0);
	fresh = (char**)malloc(sizeof(*fresh) * (ft_wordcountdel(s, c) + 1));
	if (!fresh)
		return (0);
	word = -1;
	s_char = 0;
	while (++word < ft_wordcountdel(s, c))
	{
		w_char = 0;
		if (!(fresh[word] = ft_strnew(ft_wordlendel(&s[s_char], c) + 1)))
			fresh[word] = NULL;
		while (s[s_char] == c)
			s_char++;
		while ((s[s_char] != c) && (s[s_char] != '\0'))
			fresh[word][w_char++] = s[s_char++];
		fresh[word][w_char] = '\0';
	}
	fresh[word] = 0;
	return (fresh);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:09:15 by tramants          #+#    #+#             */
/*   Updated: 2018/09/21 08:20:56 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "mini_shell.h"

static	int		read_data(int const fd, char **temp)
{
	int		count;
	char	*storage;
	char	*local_temp;

	if (!(storage = ft_strnew(BUFF_SIZE)))
		return (-1);
	count = read(fd, storage, BUFF_SIZE);
	if (count > 0)
	{
		storage[count] = 0;
		if (!(local_temp = ft_strjoin(*temp, storage)))
			return (-1);
		free(*temp);
		*temp = local_temp;
		free(storage);
	}
	if (count == 0)
		free(storage);
	return (count);
}

int				get_next_line(const int fd, char **line)
{
	static	char	*temp;
	char			*string;
	int				i;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!temp && (!(temp = ft_strnew(BUFF_SIZE))))
		return (-1);
	string = ft_strchr(temp, '\n');
	while (!string)
	{
		i = read_data(fd, &temp);
		if (i == 0 && !ft_strlen(temp))
			return (0);
		if (i == 0)
			ft_strcat(temp, "\n");
		if (i < 0)
			return (-1);
		string = ft_strchr(temp, '\n');
	}
	if (!(*line = ft_strsub(temp, 0, ft_strlen(temp) - ft_strlen(string))))
		return (-1);
	ft_strcpy(temp, string + 1);
	return (1);
}

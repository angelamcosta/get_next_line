/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:24:04 by anlima            #+#    #+#             */
/*   Updated: 2022/11/10 18:36:27 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	line[BUFFER_SIZE + 1];
	char		*next_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	next_line = 0;
	if (ft_strchr(line, '\n') > -1)
		next_line = ft_strjoin(next_line, line);
	else
	{
		i = read(fd, line, BUFFER_SIZE);
		while (i > 0)
		{
			line[i] = '\0';
			next_line = ft_strjoin(next_line, line);
			if (ft_strchr(line, '\n'))
				break ;
			i = read(fd, line, BUFFER_SIZE);
		}
	}
	if (!next_line || *next_line == '\0')
		return (0);
	ft_strcpy(line, &line[ft_strlen(line)]);
	return (next_line);
}

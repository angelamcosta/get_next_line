/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:24:04 by anlima            #+#    #+#             */
/*   Updated: 2022/10/18 15:18:31 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_str_free(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

static void	ft_parse_line(char **line, char **next_line)
{
	int		i;
	char	*temp;

	i = 0;
	if (!*line || *line[0] == '\0')
		return ;
	while (*line[i] != '\0' && *line[i] != '\n')
		i++;
	if (*line[i] == '\n')
		i++;
	*next_line = ft_substr(*line, 0, i);
	temp = ft_strdup(*line);
	ft_str_free(*line);
	*line = ft_substr(temp, i, ft_strlen(temp));
	ft_str_free(temp);
}

static void	ft_read(int fd, char **line)
{
	int		len;
	char	*buf;
	char	*temp;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return ;
	len = read(fd, buf, BUFFER_SIZE);
	temp = NULL;
	while (len > 0)
	{
		buf[len] = '\0';
		temp = ft_strjoin(*line, buf);
		ft_str_free(*line);
		*line = ft_strdup(ft_strjoin(temp, buf));
		ft_str_free(temp);
		if (ft_strchr(*line, '\n') >= 0)
			break ;
		len = read(fd, buf, BUFFER_SIZE);
	}
	ft_str_free(buf);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next_line = NULL;
	ft_read(fd, &line);
	if (!line || *line == '\0')
		return (NULL);
	ft_parse_line(&line, &next_line);
	return (next_line);
}

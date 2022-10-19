/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:24:04 by anlima            #+#    #+#             */
/*   Updated: 2022/10/19 12:19:28 by anlima           ###   ########.fr       */
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

	if (*line == NULL || *line[0] == '\0')
		return ;
	i = ft_strchr(*line, '\n');
	if (i == -1)
		i = ft_strchr(*line, '\0');
	else
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

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	len = read(fd, buf, BUFFER_SIZE);
	temp = NULL;
	while (len > 0)
	{
		buf[len] = '\0';
		temp = ft_strdup(*line);
		ft_str_free(*line);
		*line = ft_strjoin(temp, buf);
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
	if (line != NULL && *line != '\0')
		ft_parse_line(&line, &next_line);
	return (next_line);
}

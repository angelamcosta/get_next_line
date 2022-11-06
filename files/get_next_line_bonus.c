/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:24:04 by anlima            #+#    #+#             */
/*   Updated: 2022/11/06 21:59:41 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_str_free(char *s);
static void	ft_parse_line(char **line, char **next_line);
static void	ft_read(int fd, char **line);

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next_line = NULL;
	if (ft_strchr(line[fd], '\n') >= 0)
		ft_parse_line(&line[fd], &next_line);
	else
	{
		ft_read(fd, &line[fd]);
		if (line[fd] != NULL && *line[fd] != '\0')
			ft_parse_line(&line[fd], &next_line);
	}
	return (next_line);
}

static void	ft_str_free(char *s)
{
	if (s)
		free(s);
}

static void	ft_parse_line(char **line, char **next_line)
{
	int		i;
	char	*temp;

	i = ft_strchr(*line, '\n') + 1;
	if (i <= 0)
		i = ft_strchr(*line, '\0');
	if (i == -1)
		return ;
	*next_line = ft_substr(*line, 0, i);
	temp = ft_strdup(&line[0][i]);
	ft_str_free(*line);
	*line = ft_strdup(temp);
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
	while (len > 0)
	{
		buf[len] = '\0';
		temp = ft_strjoin(*line, buf);
		ft_str_free(*line);
		*line = ft_strdup(temp);
		ft_str_free(temp);
		if (ft_strchr(*line, '\n') > -1)
			break ;
		len = read(fd, buf, BUFFER_SIZE);
	}
	ft_str_free(buf);
}

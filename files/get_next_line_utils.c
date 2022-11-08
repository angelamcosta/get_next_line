/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:25:50 by anlima            #+#    #+#             */
/*   Updated: 2022/11/08 12:01:17 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int i)
{
	char	*joined;
	int		j;

	joined = malloc(ft_strlen(&s1[i]) + ft_strlen(s2) + 1);
	if (!joined)
		return (0);
	j = 0;
	while (s1 && s1[i])
		joined[j++] = s1[i++];
	if (s1)
		free(s1);
	while (s2 && *s2)
		joined[j++] = *s2++;
	joined[j] = '\0';
	return (joined);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	if (!s || s[i] != c)
		return (-1);
	return (i);
}

void	ft_parse_line(char **line, char **next_line)
{
	int		i;

	i = ft_strchr(*line, '\n') + 1;
	if (i <= 0)
		i = ft_strchr(*line, '\0');
	*next_line = ft_strjoin(*line, 0, i);
	*line = ft_strjoin(&*line[i], 0, 0);
}

void	ft_read(int fd, char **line)
{
	int		len;
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	len = read(fd, buf, BUFFER_SIZE);
	while (len > 0)
	{
		buf[len] = '\0';
		*line = ft_strjoin(*line, buf, 0);
		if (ft_strchr(buf, '\n') > -1)
			break ;
		len = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
}

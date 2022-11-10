/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:25:50 by anlima            #+#    #+#             */
/*   Updated: 2022/11/10 15:17:51 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		i;

	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (0);
	i = -1;
	while (s1 && *s1)
		joined[++i] = *s1++;
	free(s1);
	while (s2 && *s2)
		joined[++i] = *s2++;
	joined[++i] = '\0';
	return (joined);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = -1;
	if (!s || *s == '\0')
		return (++i);
	while (s[++i])
		;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	if (s && s[i] && s[i] == c)
		return (i);
	return (-1);
}

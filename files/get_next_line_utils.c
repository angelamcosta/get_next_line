/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:25:50 by anlima            #+#    #+#             */
/*   Updated: 2022/11/10 14:59:57 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		i;

	if (ft_strchr(s2, '\n') > -1)
		s2 += ((ft_strchr(s2, '\n')) + 1);
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

int	ft_strlen(char *s)
{
	int	i;

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
	while (s && s[i] != c)
		i++;
	if (s && s[i] == c)
		return (i);
	return (-1);
}

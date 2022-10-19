/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:25:50 by anlima            #+#    #+#             */
/*   Updated: 2022/10/19 09:28:19 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	if (!src)
		return (ft_strdup(""));
	copy = malloc(ft_strlen(src) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (NULL);
	if (len > ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	subs = (char *)malloc(len + 1);
	if (!subs)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		subs[i++] = s[start++];
	subs[i] = '\0';
	return (subs);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	joined = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!joined)
		return (NULL);
	while (s1 && *s1)
		joined[i++] = *s1++;
	while (s2 && *s2)
		joined[i++] = *s2++;
	joined[i] = '\0';
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

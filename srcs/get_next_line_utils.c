/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <pshamkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:33:44 by pshamkha          #+#    #+#             */
/*   Updated: 2024/04/23 16:30:04 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	l;
	char	*p;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	l = 0;
	p = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0')
		p[l++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		p[l++] = s2[i++];
	p[l] = '\0';
	return (p);
}

char	*ft_strdup(const char *str)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		++i;
	p = (char *) malloc(sizeof(char) * (i + 1));
	if (p != NULL)
	{
		while (j < i)
		{
			p[j] = str[j];
			++j;
		}
		p[j] = '\0';
	}
	return (p);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char) c && *str != '\0')
		++str;
	if (*str == (char) c || c == '\0')
		return ((char *) str);
	return (0);
}

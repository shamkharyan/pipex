/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:34:01 by pshamkha          #+#    #+#             */
/*   Updated: 2024/01/27 19:28:42 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*p;

	if (s == NULL)
		return (NULL);
	l = 0;
	if (ft_strlen(s) <= start)
		return (ft_calloc(1, 1));
	while (s[l] != '\0' && l < len)
		++l;
	p = malloc(sizeof(char) * (l + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i != l)
	{
		p[i] = s[start + i];
		++i;
	}
	p[i] = '\0';
	return (p);
}

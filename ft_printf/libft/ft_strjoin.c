/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:13:56 by pshamkha          #+#    #+#             */
/*   Updated: 2024/01/27 19:25:57 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

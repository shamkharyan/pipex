/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:02:25 by pshamkha          #+#    #+#             */
/*   Updated: 2024/01/30 12:04:39 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	a;
	size_t	b;

	if (s1 == NULL)
		return (NULL);
	a = 0;
	b = ft_strlen(s1) - 1;
	while (ft_checkset(s1[a], set) && s1[a] != '\0')
		++a;
	while (ft_checkset(s1[b], set) && b >= a)
		--b;
	return (ft_substr(s1, a, b - a + 1));
}

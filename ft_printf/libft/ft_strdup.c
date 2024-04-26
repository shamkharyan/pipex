/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:19:58 by pshamkha          #+#    #+#             */
/*   Updated: 2024/01/28 18:03:16 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

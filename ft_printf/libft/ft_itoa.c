/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:45:21 by pshamkha          #+#    #+#             */
/*   Updated: 2024/01/27 19:18:49 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nblen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t			len;
	char			*p;
	unsigned int	un;

	len = ft_nblen(n);
	p = (char *) malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	p[len] = '\0';
	if (n < 0)
		un = -n;
	else
		un = n;
	while (len > 0)
	{
		p[--len] = un % 10 + '0';
		un /= 10;
	}
	if (n < 0)
		p[0] = '-';
	return (p);
}

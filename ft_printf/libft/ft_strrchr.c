/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:02:35 by pshamkha          #+#    #+#             */
/*   Updated: 2024/01/27 19:28:09 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*p;

	p = 0;
	while (*str != '\0')
	{
		if (*str == (char) c)
			p = str;
		++str;
	}
	if ((char) c == '\0')
		return ((char *) str);
	return ((char *)(p));
}

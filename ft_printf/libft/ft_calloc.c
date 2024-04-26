/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:50:06 by pshamkha          #+#    #+#             */
/*   Updated: 2024/01/27 20:10:44 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	if (n == 0 || size == 0)
		return (malloc(1));
	if (n > INT_MAX / size)
		return (NULL);
	p = malloc(n * size);
	if (p != NULL)
		ft_bzero(p, n * size);
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:50:14 by pshamkha          #+#    #+#             */
/*   Updated: 2024/02/27 17:50:20 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcharf(int c, t_flags flags)
{
	int	len;
	int	padding;

	len = 0;
	padding = flags.width - 1;
	if (flags.minus == 0)
	{
		while (padding-- > 0)
		{
			ft_putchar_fd(' ', 1);
			++len;
		}
	}
	ft_putchar_fd((char) c, 1);
	++len;
	if (flags.minus != 0)
	{
		while (padding-- > 0)
		{
			ft_putchar_fd(' ', 1);
			++len;
		}
	}
	return (len);
}

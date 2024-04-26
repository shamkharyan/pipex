/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:51:25 by pshamkha          #+#    #+#             */
/*   Updated: 2024/02/27 17:51:29 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(void *ptr)
{
	uintptr_t	ptr_num;
	int			ptr_len;

	if (ptr == NULL)
		return (ft_strlen(PTRNULL));
	ptr_len = 2;
	ptr_num = (uintptr_t) ptr;
	while (ptr_num != 0)
	{
		ptr_num /= 16;
		++ptr_len;
	}
	return (ptr_len);
}

static void	ft_putptr(void *ptr)
{
	uintptr_t	ptr_val;
	char		buff[20];
	char		*ptr_buff;

	if (ptr == NULL)
	{
		ft_putstr_fd(PTRNULL, 1);
		return ;
	}
	ptr_buff = &buff[19];
	*(ptr_buff--) = '\0';
	ptr_val = (uintptr_t) ptr;
	while (ptr_val != 0)
	{
		if (ptr_val % 16 < 10)
			*(ptr_buff--) = ptr_val % 16 + '0';
		else
			*(ptr_buff--) = ptr_val % 16 - 10 + 'a';
		ptr_val /= 16;
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(ptr_buff + 1, 1);
}

int	ft_putptrf(void *ptr, t_flags flags)
{
	int	len;

	len = ft_ptrlen(ptr);
	flags.width -= len;
	if (flags.minus != 0)
	{
		ft_putptr(ptr);
		while (flags.width-- > 0)
		{
			ft_putchar_fd(' ', 1);
			++len;
		}
	}
	else
	{
		while (flags.width-- > 0)
		{
			ft_putchar_fd(' ', 1);
			++len;
		}
		ft_putptr(ptr);
	}
	return (len);
}

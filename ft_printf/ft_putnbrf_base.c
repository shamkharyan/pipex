/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:51:03 by pshamkha          #+#    #+#             */
/*   Updated: 2024/02/27 17:51:06 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen_base(unsigned int un, unsigned int base, int precision)
{
	int	len;

	len = 0;
	if (un == 0 && precision == 0)
		return (0);
	if (un == 0)
		return (1);
	while (un != 0)
	{
		un /= base;
		++len;
	}
	return (len);
}

static void	ft_putnbr_base(unsigned int un,
	char specifier, unsigned int base, int precision)
{
	if (precision == 0 && un == 0)
		return ;
	precision = 1;
	if (un >= base)
	{
		ft_putnbr_base(un / base, specifier, base, precision);
		ft_putnbr_base(un % base, specifier, base, precision);
	}
	else if (un >= 10 && specifier == 'x')
		ft_putchar_fd(un - 10 + 'a', 1);
	else if (un >= 10 && specifier == 'X')
		ft_putchar_fd(un - 10 + 'A', 1);
	else
		ft_putchar_fd(un + '0', 1);
}

static void	ft_putnbrf_base_width(unsigned int un,
		t_flags *flags, int *len, int zero)
{
	zero = (flags->precision < 0 && zero);
	if (flags->hash != 0 && un != 0)
	{
		flags->width -= 2;
		(*len) += 2;
		if (zero != 0)
		{
			flags->hash = 0;
			if (flags->specifier == 'x')
				ft_putstr_fd("0x", 1);
			else if (flags->specifier == 'X')
				ft_putstr_fd("0X", 1);
		}
	}
	while (flags->width-- > 0)
	{
		if (zero != 0)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		(*len)++;
	}
}

static void	ft_putnbrf_base_precision(unsigned int un,
		t_flags *flags, int *len, int base)
{
	flags->precision -= ft_nbrlen_base(un, base, flags->precision);
	if (flags->hash != 0 && un != 0)
	{
		if (flags->specifier == 'x')
			ft_putstr_fd("0x", 1);
		else if (flags->specifier == 'X')
			ft_putstr_fd("0X", 1);
	}
	while (flags->precision > 0)
	{
		ft_putchar_fd('0', 1);
		flags->precision--;
		(*len)++;
	}
}

int	ft_putnbrf_base(unsigned int un, t_flags flags, unsigned int base)
{
	int	len;
	int	prec;

	len = 0;
	prec = flags.precision;
	if (flags.precision > ft_nbrlen_base(un, base, prec))
		flags.width -= flags.precision;
	else
		flags.width -= ft_nbrlen_base(un, base, prec);
	if (flags.minus == 0)
	{
		ft_putnbrf_base_width(un, &flags, &len, flags.zero);
		ft_putnbrf_base_precision(un, &flags, &len, base);
		ft_putnbr_base(un, flags.specifier, base, prec);
	}
	else
	{
		ft_putnbrf_base_precision(un, &flags, &len, base);
		ft_putnbr_base(un, flags.specifier, base, prec);
		ft_putnbrf_base_width(un, &flags, &len, 0);
	}
	len += ft_nbrlen_base(un, base, prec);
	return (len);
}

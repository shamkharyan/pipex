/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:50:38 by pshamkha          #+#    #+#             */
/*   Updated: 2024/02/27 17:50:45 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_abs(int n, int precision)
{
	if (n == 0 && precision == 0)
		return ;
	else if (n == -2147483648)
		ft_putstr_fd("2147483648", 1);
	else if (n < 0)
		ft_putnbr_fd(-n, 1);
	else
		ft_putnbr_fd(n, 1);
}

static int	ft_nbrlen_abs(int n, int precision)
{
	unsigned int	nb;
	int				len;

	len = 1;
	if (n == 0 && precision == 0)
		return (0);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	while (nb >= 10)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

static void	ft_putnbrf_width(int *is_neg, int *len, t_flags *flags, int zero)
{
	zero = (flags->precision < 0 && zero);
	if (*is_neg != 0 || flags->plus != 0 || flags->space != 0)
	{
		flags->width--;
		(*len)++;
		if (zero != 0)
		{
			if (*is_neg != 0)
				ft_putchar_fd('-', 1);
			else if (flags->plus != 0)
				ft_putchar_fd('+', 1);
			else
				ft_putchar_fd(' ', 1);
			flags->space = 0;
			flags->plus = 0;
			*is_neg = 0;
		}
	}
	while (flags->width-- > 0)
	{
		ft_putchar_fd(' ' + zero * ('0' - ' '), 1);
		(*len)++;
	}
}

static void	ft_putnbrf_precision(int n, int *is_neg, int *len, t_flags *flags)
{
	flags->precision -= ft_nbrlen_abs(n, flags->precision);
	if (*is_neg != 0)
		ft_putchar_fd('-', 1);
	else if (*is_neg == 0 && flags->plus != 0)
		ft_putchar_fd('+', 1);
	else if (*is_neg == 0 && flags->space != 0)
		ft_putchar_fd(' ', 1);
	while (flags->precision > 0)
	{
		ft_putchar_fd('0', 1);
		flags->precision--;
		(*len)++;
	}
}

int	ft_putnbrf(int n, t_flags flags)
{
	int	len;
	int	is_neg;
	int	prec;

	len = 0;
	is_neg = (n < 0);
	prec = flags.precision;
	if (ft_nbrlen_abs(n, prec) > flags.precision)
		flags.width -= ft_nbrlen_abs(n, prec);
	else
		flags.width -= flags.precision;
	if (flags.minus == 0)
	{
		ft_putnbrf_width(&is_neg, &len, &flags, flags.zero);
		ft_putnbrf_precision(n, &is_neg, &len, &flags);
		ft_putnbr_abs(n, prec);
	}
	else
	{
		ft_putnbrf_precision(n, &is_neg, &len, &flags);
		ft_putnbr_abs(n, prec);
		ft_putnbrf_width(&is_neg, &len, &flags, 0);
	}
	len += ft_nbrlen_abs(n, prec);
	return (len);
}

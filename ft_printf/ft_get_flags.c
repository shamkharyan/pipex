/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:48:42 by pshamkha          #+#    #+#             */
/*   Updated: 2024/02/27 17:49:12 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_zero(t_flags *flags)
{
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->specifier = 0;
}

static int	ft_get_first(const char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == '-')
			flags->minus = 1;
		else if (str[i] == '+')
			flags->plus = 1;
		else if (str[i] == ' ')
			flags->space = 1;
		else if (str[i] == '#')
			flags->hash = 1;
		else if (str[i] == '0')
			flags->zero = 1;
		else
			break ;
		++i;
	}
	return (i);
}

static int	ft_get_width(const char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
	{
		flags->width = 10 * flags->width + str[i] - '0';
		++i;
	}
	return (i);
}

static int	ft_get_precision(const char *str, t_flags *flags)
{
	int	i;

	if (str[0] != '.')
	{
		flags->precision = -1;
		return (0);
	}
	i = 1;
	flags->precision = 0;
	while (ft_isdigit(str[i]))
	{
		flags->precision = 10 * flags->precision + (str[i]) - '0';
		++i;
	}
	return (i);
}

int	ft_get_flags(const char *str, t_flags *flags)
{
	char	*ptr;

	ft_set_zero(flags);
	ptr = (char *) str;
	ptr += ft_get_first(ptr, flags);
	ptr += ft_get_width(ptr, flags);
	ptr += ft_get_precision(ptr, flags);
	flags->specifier = *ptr;
	return (ptr - str + 1);
}

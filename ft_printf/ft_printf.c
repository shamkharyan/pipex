/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:22:44 by pshamkha          #+#    #+#             */
/*   Updated: 2024/02/06 17:11:48 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(va_list *args, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->specifier == 'd' || flags->specifier == 'i')
		len = ft_putnbrf(va_arg(*args, int), *flags);
	else if (flags->specifier == 'u')
		len = ft_putnbrf_base(va_arg(*args, unsigned int), *flags, 10);
	else if (flags->specifier == 'x' || flags->specifier == 'X')
		len = ft_putnbrf_base(va_arg(*args, unsigned int), *flags, 16);
	else if (flags->specifier == 'p')
		len = ft_putptrf(va_arg(*args, void *), *flags);
	else if (flags->specifier == 'c')
		len = ft_putcharf(va_arg(*args, int), *flags);
	else if (flags->specifier == 's')
		len = ft_putstrf(va_arg(*args, char *), *flags);
	else if (flags->specifier == '%')
		len = ft_putcharf('%', *flags);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	char	*ptr;
	int		len;

	va_start(args, format);
	ptr = (char *) format;
	len = 0;
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			if (*(++ptr) == '\0')
				break ;
			ptr += ft_get_flags(ptr, &flags);
			len += ft_print(&args, &flags);
		}
		else
		{
			ft_putchar_fd(*ptr++, 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:51:43 by pshamkha          #+#    #+#             */
/*   Updated: 2024/02/27 17:51:47 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstrf_width(int *padding, int *len)
{
	while ((*padding)-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*len)++;
	}
}

static void	ft_putstrf_precision(const char *str, int *print_len, int *len)
{
	while ((*print_len)-- > 0)
	{
		ft_putchar_fd(*str++, 1);
		(*len)++;
	}
}

int	ft_putstrf(const char *str, t_flags flags)
{
	int		len;
	int		print_len;
	int		padding;
	char	*str_copy;

	str_copy = (char *) str;
	if (str == NULL)
		str_copy = ft_strdup(STRNULL);
	len = 0;
	if (flags.precision < 0 || flags.precision > (int) ft_strlen(str_copy))
		print_len = ft_strlen(str_copy);
	else
		print_len = flags.precision;
	if (flags.width > print_len)
		padding = flags.width - print_len;
	else
		padding = 0;
	if (flags.minus == 0)
		ft_putstrf_width(&padding, &len);
	ft_putstrf_precision(str_copy, &print_len, &len);
	if (flags.minus != 0)
		ft_putstrf_width(&padding, &len);
	if (str == NULL)
		free(str_copy);
	return (len);
}

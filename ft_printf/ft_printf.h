/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:04:18 by pshamkha          #+#    #+#             */
/*   Updated: 2024/02/27 18:20:33 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

# define PTRNULL "0x0"
# define STRNULL "(null)"

typedef struct s_flags
{
	int	hash;
	int	space;
	int	plus;
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	specifier;
}				t_flags;

int	ft_printf(const char *format, ...);
int	ft_putptrf(void *ptr, t_flags flags);
int	ft_putstrf(const char *str, t_flags flags);
int	ft_putnbrf(int n, t_flags flags);
int	ft_putnbrf_base(unsigned int n, t_flags flags, unsigned int base);
int	ft_putcharf(int c, t_flags flags);
int	ft_get_flags(const char *str, t_flags *flags);

#endif

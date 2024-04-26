/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:29:54 by pshamkha          #+#    #+#             */
/*   Updated: 2024/01/27 16:33:54 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*next;

	if (lst == NULL)
		return (0);
	next = lst->next;
	count = 1;
	while (next != NULL)
	{
		next = next->next;
		++count;
	}
	return (count);
}

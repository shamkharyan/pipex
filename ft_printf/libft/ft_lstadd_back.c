/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:44:36 by pshamkha          #+#    #+#             */
/*   Updated: 2024/01/27 16:51:05 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*next;

	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}
	next = (*lst);
	while (next->next != NULL)
		next = next->next;
	next->next = new;
}

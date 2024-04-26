/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:31:08 by pshamkha          #+#    #+#             */
/*   Updated: 2024/01/28 18:04:37 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	int		flag;
	size_t	count;
	size_t	i;

	flag = 1;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (flag == 1 && s[i] != c)
		{
			++count;
			flag = 0;
		}
		if (flag == 0 && s[i] == c)
			flag = 1;
		++i;
	}
	return (count);
}

static size_t	ft_strlen_c(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		++i;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	char	*str;
	size_t	items;

	if (s == NULL)
		return (NULL);
	items = word_count(s, c);
	strs = (char **) malloc(sizeof(char *) * (items + 1));
	if (strs == NULL)
		return (NULL);
	str = (char *) s;
	i = 0;
	while (i < items)
	{
		if (ft_strlen_c(str, c) != 0)
		{
			strs[i++] = ft_substr(str, 0, ft_strlen_c(str, c));
			str += ft_strlen_c(str, c) + 1;
		}
		else
			++str;
	}
	strs[i] = NULL;
	return (strs);
}

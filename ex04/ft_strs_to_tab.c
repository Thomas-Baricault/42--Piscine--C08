/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:54:57 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/04 14:39:25 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str	create_stock_str(char *str)
{
	struct s_stock_str	result;
	int					length;

	length = 0;
	while (str[length])
		length++;
	result.size = length;
	result.str = str;
	result.copy = malloc(sizeof(char) * (length + 1));
	if (result.copy)
	{
		result.copy[length] = '\0';
		while (--length >= 0)
			result.copy[length] = str[length];
	}
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;

	tab = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	tab[ac].size = 0;
	tab[ac].str = NULL;
	tab[ac].copy = NULL;
	while (--ac >= 0)
	{
		tab[ac] = create_stock_str(av[ac]);
		if (tab[ac].copy == NULL)
		{
			while (tab[ac++].copy)
				free(tab[ac].copy);
			free(tab);
			return (NULL);
		}
	}
	return (tab);
}

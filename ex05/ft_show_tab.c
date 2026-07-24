/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:18:13 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/08 12:07:11 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	putnbr(int nb)
{
	char	c;

	if (nb > 9)
		putnbr(nb / 10);
	c = '0' + nb % 10;
	write(1, &c, 1);
	return ;
}

void	ft_show_tab(struct s_stock_str *par)
{
	char	*ptr;

	while ((*par).str)
	{
		ptr = (*par).str;
		while (*ptr)
			write(1, ptr++, 1);
		write(1, "\n", 1);
		putnbr((*par).size);
		write(1, "\n", 1);
		ptr = (*par).copy;
		while (*ptr)
			write(1, ptr++, 1);
		write(1, "\n", 1);
		par++;
	}
	return ;
}

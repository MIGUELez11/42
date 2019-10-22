/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 00:35:18 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/09 08:36:44 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	short int x;
	short int y;
	short int z;

	x = -1;
	while (x++ < 7)
	{
		y = x;
		while (y++ < 8)
		{
			z = y;
			while (z++ < 9)
			{
				ft_putchar('0' + x);
				ft_putchar('0' + y);
				ft_putchar('0' + z);
				if (x < 7)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}

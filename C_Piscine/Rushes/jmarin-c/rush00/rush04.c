/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil-bon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:43:13 by jgil-bon          #+#    #+#             */
/*   Updated: 2019/10/06 23:29:53 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int col, int row)
{
	int x;
	int y;
	int col1;

	col1 = col > 1 && row > 1;
	y = 0;
	while (y < row)
	{
		x = 0;
		while (x < col)
		{
			if ((y == 0 && x == 0) || (y == row - 1 && x == col - 1 && col1))
				ft_putchar('A');
			else if ((y == row - 1 && x == 0) || (y == 0 && x == col - 1))
				ft_putchar('C');
			else if ((x == 0 || x == col - 1) || (y == 0 || y == row - 1))
				ft_putchar('B');
			else
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

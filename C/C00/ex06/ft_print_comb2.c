/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:15:20 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/10 10:24:36 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int numbers[4];

	while (numbers[0]++ <= 9)
	{
		numbers[1] = 0;
		while (numbers[1]++ <= 8)
		{
			numbers[2] = numbers[0] - 1;
			while (numbers[2]++ <= 9)
			{
				numbers[3] = numbers[1];
				while (numbers[3]++ <= 9)
				{
					ft_putchar(numbers[0] - 1 + '0');
					ft_putchar(numbers[1] - 1 + '0');
					ft_putchar(' ');
					ft_putchar(numbers[2] - 1 + '0');
					ft_putchar(numbers[3] - 1 + '0');
					if (numbers[0] - 1 != 9 || numbers[1] - 1 != 8)
						write(1, ", ", 2);
				}
			}
		}
	}
}

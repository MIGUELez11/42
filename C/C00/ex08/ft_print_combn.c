/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 23:49:25 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/09 11:39:16 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int i;
	long int n;

	n = nb;
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	else if (n == 0)
	{
		write(1, "0", 1);
	}
	i = 1;
	while (nb / i != 0)
	{
		i *= 10;
	}
	while (i != 1)
	{
		i /= 10;
		ft_putchar((n % (10 * i) - n % i) / i + '0');
	}
}

void	ft_recursive_print_n(int prev_num, int pos, int max_pos, int fpos)
{
	int num;

	if (prev_num != -1)
		num = prev_num % 10;
	else
	{
		prev_num = 0;
		num = -1;
	}
	while (num++ < 9)
	{
		fpos = pos == 0 ? num : fpos;
		if (pos <= max_pos - 1)
			ft_recursive_print_n(prev_num * 10 + num, pos + 1, max_pos, fpos);
		if (pos == max_pos - 1)
		{
			if (fpos == 0 && max_pos > 1)
				ft_putnbr(0);
			ft_putnbr(prev_num * 10 + num);
			if (fpos != 9 - (max_pos - 1))
				write(1, ", ", 2);
		}
	}
}

void	ft_print_combn(int n)
{
	if (n > 0 && n < 10)
	{
		ft_recursive_print_n(-1, 0, n, 0);
	}
}

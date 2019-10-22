/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:55:59 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/10 10:25:06 by mflorido         ###   ########.fr       */
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
	if (nb < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	else if (n == 0)
	{
		ft_putchar('0');
	}
	i = 1;
	while (n / i != 0)
	{
		i *= 10;
	}
	while (i != 1)
	{
		i /= 10;
		ft_putchar((n % (10 * i) - n % i) / i + '0');
	}
}

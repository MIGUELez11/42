/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:09:27 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/17 11:00:30 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_dec_to_hex(unsigned char c)
{
	ft_putchar('\\');
	if (c / 16 <= 9)
		ft_putchar(c / 16 + '0');
	else
		ft_putchar(c / 16 + 'a' - 10);
	if (c % 16 <= 9)
		ft_putchar(c % 16 + '0');
	else
		ft_putchar(c % 16 + 'a' - 10);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 31 && str[i] > 0)
			ft_dec_to_hex(str[i]);
		else
			write(1, str + i, 1);
		i++;
	}
}

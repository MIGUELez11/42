/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_abs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:46:49 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/03 20:53:43 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_abs(int n, int fd)
{
	char		c;
	long int	n2;

	if (n < 0)
		n2 = -(long int)n;
	else
		n2 = n;
	if (n2 > 9)
		putnbr_abs(n2 / 10, fd);
	c = (n2 % 10) + '0';
	write(fd, &c, 1);
}

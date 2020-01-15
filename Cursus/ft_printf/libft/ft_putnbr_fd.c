/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:11:53 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:45:21 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long int	n2;

	if (n < 0)
	{
		write(fd, "-", 1);
		n2 = -(long int)n;
	}
	else
		n2 = n;
	if (n2 > 9)
		ft_putnbr_fd(n2 / 10, fd);
	c = (n2 % 10) + '0';
	write(fd, &c, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:20:06 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/19 20:07:22 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int			i;
	char		*r;
	long int	n2;
	int			isneg;

	i = 1;
	isneg = 0;
	i = ft_intlen(n);
	isneg = (n < 0 ? 1 : 0);
	n2 = (n < 0 ? -(long)n : n);
	i += (isneg ? 1 : 0);
	r = ft_calloc(i + 1, sizeof(char));
	if (r == NULL)
		return (NULL);
	r[i--] = 0;
	while (i >= (isneg == 0 ? 0 : 1))
	{
		r[i] = n2 % 10 + '0';
		n2 /= 10;
		i--;
	}
	r[0] = (isneg ? '-' : r[0]);
	return (r);
}

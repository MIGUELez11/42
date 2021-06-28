/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez1 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 09:51:06 by miguelez1         #+#    #+#             */
/*   Updated: 2020/02/17 17:06:17 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	get_hex_char(unsigned long int *n)
{
	char	result;

	if (*n % 16 > 9)
		result = (*n % 16 + ('a' - 10));
	else
		result = (*n % 16 + '0');
	*n /= 16;
	return (result);
}

char	*ft_itoh(unsigned long int n)
{
	int					i;
	unsigned long int	n2;
	char				*str;
	int					isneg;

	isneg = n < 0;
	i = 1;
	n2 = n;
	while (n2 / 16)
	{
		i++;
		n2 /= 16;
	}
	str = ft_calloc(sizeof(char), (i + 1 + (n < 0)));
	if (!str)
		return (NULL);
	if (isneg)
	{
		n *= -1;
		i++;
		str[0] = '-';
	}
	while (i > isneg)
		str[i-- - 1] = get_hex_char(&n);
	return (str);
}

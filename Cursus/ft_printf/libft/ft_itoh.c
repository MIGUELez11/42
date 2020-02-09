/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez1 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 09:51:06 by miguelez1         #+#    #+#             */
/*   Updated: 2020/02/09 16:56:35 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


char	*ft_itoh(int n)
{
	int		i;
	int		n2;
	char	*str;
	int		isneg;

	isneg = 0;
	i = 1;
	n2 = n;
	while(n2 /= 16)
		i++;
	if(!(str = (char *)malloc(sizeof(char) * (i + 1 + (n < 0)))))
		return (NULL);
	if (n < 0)
	{
		isneg = 1;
		n *= -1;
		i++;
		str[0] = '-';
	}
	str[i + 1] = 0;
	while (i > isneg)
	{
		str[i-- - 1] = (n % 16 + (n % 16 > 9 ? 'a' - 10 : '0'));
		n /= 16;
	}
	return (str);
}

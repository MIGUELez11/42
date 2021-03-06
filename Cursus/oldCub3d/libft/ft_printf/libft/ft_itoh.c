/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 09:51:06 by miguelez1         #+#    #+#             */
/*   Updated: 2020/09/03 21:14:56 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_libft.h"

char	*ft_itoh(unsigned long int n)
{
	int					i;
	unsigned long int	n2;
	char				*str;
	int					isneg;

	isneg = 0;
	i = 1;
	n2 = n;
	while (n2 /= 16)
		i++;
	if (!(str = ft_calloc(sizeof(char), (i + 1 + (n < 0)))))
		return (NULL);
	if (n < 0)
	{
		isneg = 1;
		n *= -1;
		i++;
		str[0] = '-';
	}
	while (i > isneg)
	{
		str[i-- - 1] = (n % 16 + (n % 16 > 9 ? 'a' - 10 : '0'));
		n /= 16;
	}
	return (str);
}

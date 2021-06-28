/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:02:08 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/12 18:55:43 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_libft.h"

int	ft_intlen(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		if (n != 0)
			i++;
	}
	return (++i);
}

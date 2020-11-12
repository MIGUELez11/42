/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_repeated_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez1 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:27:21 by miguelez1         #+#    #+#             */
/*   Updated: 2020/01/20 17:50:39 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_repeated_char(int c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (n);
}

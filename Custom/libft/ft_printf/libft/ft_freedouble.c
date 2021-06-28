/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:33:12 by mflorido          #+#    #+#             */
/*   Updated: 2020/09/17 21:41:37 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_libft.h"

void	ft_freedouble(void **pointer)
{
	int	length;

	length = 0;
	while (pointer[length])
	{
		free(pointer[length]);
		length++;
	}
	free(pointer);
}

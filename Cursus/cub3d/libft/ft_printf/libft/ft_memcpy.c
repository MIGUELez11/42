/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:58:19 by mflorido          #+#    #+#             */
/*   Updated: 2020/09/03 21:14:56 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p1;
	char	*p2;

	i = 0;
	p1 = (char *)dst;
	p2 = (char *)src;
	if (p1 == NULL && p2 == NULL)
		return (NULL);
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dst);
}

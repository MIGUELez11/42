/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:41:32 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:44:40 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			*p1;
	unsigned char			*p2;

	i = 0;
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	if (p1 == NULL && p2 == NULL)
		return (NULL);
	while (i < n)
	{
		p1[i] = p2[i];
		if (p1[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

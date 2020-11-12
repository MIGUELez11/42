/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 09:22:01 by mflorido          #+#    #+#             */
/*   Updated: 2020/09/03 21:14:56 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	r;
	size_t	i;
	size_t	dstsize;

	dstsize = ft_strlen(dst);
	i = 0;
	if (n <= dstsize)
		r = (ft_strlen(src) + n);
	else
	{
		r = (dstsize + ft_strlen(src));
		while (i + dstsize + 1 < n && src[i])
		{
			dst[i + dstsize] = src[i];
			i++;
		}
		dst[i + dstsize] = 0;
	}
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 09:22:01 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:45:54 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t dstsize;
	size_t srcsize;
	size_t r;

	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (n < dstsize)
		r = (srcsize + n);
	else if (n == dstsize)
		r = (dstsize + n - 1);
	else
		r = (dstsize + srcsize);
	i = dstsize;
	while (src[i - dstsize] && i < n - 1)
	{
		dst[i] = src[i - dstsize];
		i++;
	}
	if (n == 0)
		i = dstsize;
	dst[i] = 0;
	return (r);
}

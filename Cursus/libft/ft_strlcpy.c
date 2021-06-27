/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 09:09:42 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:59:02 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ssz;

	i = 0;
	ssz = 0;
	if (src)
		ssz = ft_strlen(src);
	if (dst == NULL || !dstsize)
		return (ssz);
	while (dst > src && i < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (dst <= src && dstsize - 1 > 0 && src[i])
	{
		dst[dstsize - 1] = src[dstsize - 1];
		dstsize--;
	}
	if (dstsize < ssz)
		i--;
	dst[i] = 0;
	return (ssz);
}

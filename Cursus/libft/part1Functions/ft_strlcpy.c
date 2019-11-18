/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 09:09:42 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/13 10:47:17 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ssz;

	i = 0;
	if (dst == NULL)
		return (ssz);
	ssz = ft_strlen(src);
	if (!dstsize)
		return (ssz);
	if (dst > src)
		while (i < dstsize && src[i])
		{
			dst[i] = src[i];
			i++;
		}
	else
		while (dstsize - 1 > 0 && src[i])
		{
			dst[dstsize - 1] = src[dstsize - 1];
			dstsize--;
		}
	if (dstsize < ssz)
		i--;
	dst[i] = 0;
	return (ssz);
}

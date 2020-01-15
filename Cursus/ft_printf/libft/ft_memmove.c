/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:37:57 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:45:01 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*p1;
	char	*p2;

	p1 = (char *)dst;
	p2 = (char *)src;
	if (p1 == NULL && p2 == NULL)
		return (NULL);
	i = 0;
	if (src > dst)
		while (i < len)
		{
			p1[i] = p2[i];
			i++;
		}
	else
	{
		while (len > 0)
		{
			p1[len - 1] = p2[len - 1];
			len--;
		}
	}
	i = 0;
	return (dst);
}

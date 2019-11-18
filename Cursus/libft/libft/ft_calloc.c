/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:15:36 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:43:19 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;
	size_t	i;

	r = malloc(size * count);
	i = 0;
	if (r == NULL)
		return (NULL);
	ft_bzero(r, count * size);
	return (r);
}

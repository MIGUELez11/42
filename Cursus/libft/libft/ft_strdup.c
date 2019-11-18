/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:47:09 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:45:41 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*r;
	int		i;

	length = ft_strlen(s1) + 1;
	r = ft_calloc(length, sizeof(char));
	i = 0;
	if (r != NULL)
	{
		while (i < length - 1)
		{
			r[i] = s1[i];
			i++;
		}
		r[i] = 0;
	}
	return (r);
}

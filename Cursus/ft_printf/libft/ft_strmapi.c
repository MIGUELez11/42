/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:19:09 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:46:08 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*r;

	i = 0;
	if (!s || !(r = ft_calloc(ft_strlen(s) + 1, sizeof(char))))
		return (NULL);
	while (s[i])
	{
		r[i] = (*f)(i, s[i]);
		i++;
	}
	r[i] = 0;
	return (r);
}

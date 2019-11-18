/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:24:59 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/16 15:34:57 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*r;
	size_t	i;

	if (!s)
		return (NULL);
	i = start;
	slen = ft_strlen(s);
	r = malloc((len + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	r[i] = 0;
	while (s[i] && i - start < len)
	{
		r[i - start] = s[i];
		i++;
	}
	r[i - start] = 0;
	return (r);
}

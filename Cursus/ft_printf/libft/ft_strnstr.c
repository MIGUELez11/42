/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 09:16:10 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:46:19 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			while (needle[j] && i + j < len)
			{
				if (needle[j] != haystack[i + j])
					break ;
				j++;
			}
			if (!needle[j])
				return ((char *)haystack + i);
		}
		i++;
	}
	if (needle[0] == 0)
		return ((char *)haystack);
	return (NULL);
}

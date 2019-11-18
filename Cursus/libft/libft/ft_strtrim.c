/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:11:00 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:51:57 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_containschar(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] != c)
		i++;
	if (s1[i] == c)
		return (1);
	return (0);
}

static char	*ft_allocmem(char const *s1, size_t j, size_t k)
{
	size_t size;

	size = ft_strlen(s1);
	if (k == (size_t)-1)
		return (ft_calloc(1, sizeof(char)));
	else
		return (ft_calloc(size - j - (size - k) + 2, sizeof(char)));
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*r;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = ft_strlen(s1) - 1;
	while (s1[j] && ft_containschar(set, s1[j]))
		j++;
	while (s1[k] && ft_containschar(set, s1[k]))
		k--;
	r = ft_allocmem(s1, j, k);
	if (r == NULL)
		return (NULL);
	while (i + j <= k && s1[i + j])
	{
		r[i] = s1[i + j];
		i++;
	}
	r[i] = 0;
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:44:10 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/22 10:07:01 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_nsep(char const *s, char c)
{
	int i;
	int	nsep;

	i = 0;
	nsep = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			nsep++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nsep);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	int		nsep;
	int		i;
	int		size;

	if (!s)
		return (NULL);
	nsep = ft_get_nsep(s, c);
	r = ft_calloc(nsep + 1, sizeof(char *));
	if (!r)
		return (NULL);
	r[nsep] = NULL;
	i = 0;
	while (i < nsep)
	{
		size = 0;
		while (*s == c)
			s++;
		while (s[size] && s[size] != c)
			size++;
		r[i++] = ft_substr(s, 0, size);
		s += size;
	}
	return (r);
}

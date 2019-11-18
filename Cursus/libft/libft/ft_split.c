/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:08:38 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:51:02 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_next_c(char const *s, char c)
{
	int i;

	s++;
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (++i);
}

static int	ft_get_nsep(char const *s, char c)
{
	int i;
	int nsep;

	i = 0;
	nsep = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			nsep++;
		i++;
	}
	return (++nsep);
}

static char	**ft_write_r(const char *s, char c, char **r, int j[3])
{
	while ((j[2] == -1 ? s[0] : s[j[2]]))
	{
		if (s[j[2]] == c || j[0] == -1)
		{
			if (s[j[2] + 1] != c && s[j[2] + 1])
			{
				if (j[0] > -1)
					r[j[0]][j[1]] = 0;
				j[0]++;
				r[j[0]] = ft_calloc(ft_find_next_c(s + j[2], c), sizeof(char));
				if (r[j[0]] == NULL)
					return (NULL);
				j[1] = 0;
			}
		}
		else
		{
			r[j[0]][j[1]] = s[j[2]];
			j[1]++;
		}
		j[2]++;
	}
	r[++j[0]] = NULL;
	return (r);
}

char		**ft_split(char const *s, char c)
{
	int		j[3];
	char	**r;

	j[1] = 0;
	j[0] = -1;
	if (s == NULL)
		return (NULL);
	r = ft_calloc(ft_get_nsep(s, c) + 2, sizeof(char *));
	if (r == NULL)
		return (NULL);
	j[2] = -1;
	r = ft_write_r(s, c, r, j);
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:11:00 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/20 19:59:29 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			ft_ischar(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

int			ft_frstocc(char const *s1, char const *set)
{
	int i;

	i = 0;
	while (s1[i] && ft_ischar(s1[i], set))
	{
		i++;
	}
	return (i);
}

int			ft_lsttocc(char const *s1, char const *set)
{
	int i;
	int size;

	size = ft_strlen(s1) - 1;
	i = 0;
	while (s1[size - i] && ft_ischar(s1[size - i], set))
	{
		i++;
	}
	return (size - i + 1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	start = ft_frstocc(s1, set);
	end = ((size_t)start == ft_strlen(s1) ? start : ft_lsttocc(s1, set));
	i = 0;
	r = ft_calloc((end - start) + 1, sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		r[i] = s1[i + start];
		i++;
	}
	r[i] = 0;
	return (r);
}

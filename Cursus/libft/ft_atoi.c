/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 09:00:54 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:43:08 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

static int	ft_returnvalue(int i, int numstart, int isneg, int r)
{
	if (i - numstart > 20)
	{
		if (!isneg)
			return (-1);
		return (0);
	}
	if (isneg)
		return (-r);
	return (r);
}

int			ft_atoi(const char *str)
{
	int r;
	int i;
	int isneg;
	int	numstart;

	i = 0;
	r = 0;
	isneg = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		isneg = (str[i] == '-');
		i++;
	}
	numstart = i;
	while (str[i] && ft_isdigit(str[i]))
	{
		r += str[i] - '0';
		if (ft_isdigit(str[i + 1]))
			r *= 10;
		i++;
	}
	return (ft_returnvalue(i, numstart, isneg, r));
}

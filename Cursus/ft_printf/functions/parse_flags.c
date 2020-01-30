/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getFlags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:21:41 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/30 17:05:13 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flags(t_printf_list *p_lst)
{
	char	c;

	while (!ft_strchr(p_lst->conversors, p_lst->str[++p_lst->i]))
	{
		c = p_lst->str[p_lst->i];
		if (p_lst->str[p_lst->i] == '-')
			p_lst->flags.minus = 1;
		else if (p_lst->str[p_lst->i] == '.')
		{
			p_lst->flags.point = 1;
			p_lst->flags.precision = 0;
		}
		else if (p_lst->str[p_lst->i] == '*' && p_lst->flags.point == 0)
			p_lst->flags.width = va_arg(p_lst->ap, int);
		else if (p_lst->str[p_lst->i] == '*' && p_lst->flags.point == 1)
			p_lst->flags.precision = va_arg(p_lst->ap, int);
		else if (c >= '1' && c <= '9' && p_lst->flags.point == 0)
		{
			p_lst->flags.width = ft_atoi(p_lst->str + p_lst->i);
			p_lst->i += ft_intlen(p_lst->flags.width) - 1;
		}
		else if (c >= '0' && c <= '9' && p_lst->flags.point == 1)
		{
			p_lst->flags.precision = ft_atoi(p_lst->str + p_lst->i);
			p_lst->i += ft_intlen(p_lst->flags.precision) - 1;
		}
		else if (c == '0')
			p_lst->flags.zero = 1;
		else
			return (0);

	}
	return (1);
}

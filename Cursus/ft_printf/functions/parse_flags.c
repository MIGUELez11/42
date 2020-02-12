/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getFlags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:21:41 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/12 19:36:04 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_point(t_printf_list *p_lst, char c)
{
	p_lst->flags.point = 1;
	p_lst->flags.precision = 0;
}

static void	parse_width(t_printf_list *p_lst, char c)
{
	p_lst->flags.width = ft_atoi(p_lst->str + p_lst->i);
	p_lst->i += ft_intlen(p_lst->flags.width) - 1;
}

static void	parse_precision(t_printf_list *p_lst, char c)
{
	p_lst->flags.precision = ft_atoi(p_lst->str + p_lst->i);
	p_lst->i += ft_intlen(p_lst->flags.precision) - 1;
}

int			parse_flags(t_printf_list *p_lst)
{
	char	c;
	int		prev_i;

	prev_i = p_lst->i;
	while (!ft_strchr(p_lst->conversors, p_lst->str[++p_lst->i]))
	{
		c = p_lst->str[p_lst->i];
		if (c == '-')
			p_lst->flags.minus = 1;
		else if (c == '.')
			parse_point(p_lst, c);
		else if (c == '*' && p_lst->flags.point == 0)
			p_lst->flags.width = va_arg(p_lst->ap, int);
		else if (c == '*' && p_lst->flags.point == 1)
			p_lst->flags.precision = va_arg(p_lst->ap, int);
		else if (c >= '1' && c <= '9' && p_lst->flags.point == 0)
			parse_width(p_lst, c);
		else if (c >= '0' && c <= '9' && p_lst->flags.point == 1)
			parse_precision(p_lst, c);
		else if (c == '0')
			p_lst->flags.zero = 1;
	}
	c = p_lst->str[p_lst->i];
	return (1);
}

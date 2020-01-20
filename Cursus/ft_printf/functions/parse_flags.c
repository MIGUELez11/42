/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getFlags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:21:41 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/19 23:23:08 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flags(t_printf_list *p_lst)
{
	char	c;

	c = 'a';
	while (!ft_strchr(p_lst->conversors, p_lst->str[++p_lst->i]))
	{
		c = p_lst->str[p_lst->i];
		if (p_lst->str[p_lst->i] == '-')
			p_lst->flags.minus = 1;
		else if (p_lst->str[p_lst->i] == '.')
			p_lst->flags.point = 1;
		else if (p_lst->str[p_lst->i] == '*' && p_lst->flags.point == 0)
			p_lst->flags.width = va_arg(p_lst->ap, int);
		else if (p_lst->str[p_lst->i] == '*' && p_lst->flags.point == 1)
			p_lst->flags.precision = va_arg(p_lst->ap, int);
		else if (c >= '0' && c <= '9' && p_lst->flags.point == 0)
		{
			p_lst->flags.width = ft_atoi(p_lst->str + p_lst->i);
			p_lst->i += ft_intlen(p_lst->flags.width) - 1;
		}
		else if (c >= '0' && c <= '9' && p_lst->flags.point == 1)
		{
			p_lst->flags.precision = ft_atoi(p_lst->str + p_lst->i);
			p_lst->i += ft_intlen(p_lst->flags.precision) - 1;
		}
	}
//	printf("- %d | . %d | * %d | w %d | p %d\n", p_lst->flags.minus, p_lst->flags.point, p_lst->flags.asterisk, p_lst->flags.width, p_lst->flags.precision);
	return (1);
}

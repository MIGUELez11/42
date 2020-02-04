/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 08:03:57 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/03 20:50:52 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parser(t_printf_list *p_lst)
{
	char c;

	if (parse_flags(p_lst))
	{
		c = p_lst->str[p_lst->i];
		if (c == 'c')
			parse_char(p_lst);
		else if (c == 's')
			parse_string(p_lst);
		else if (c == '%')
			parse_percent(p_lst);
		else if (c == 'd' || c == 'i')
			parse_int(p_lst);
		else if (c == 'u')
			parse_uint(p_lst);
		return (1);
	}
	return (0);
}

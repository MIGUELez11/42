/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 08:06:26 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/19 23:11:20 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			flags_init(t_printf_list *p_lst)
{
	p_lst->flags.minus = 0;
	p_lst->flags.width = 0;
	p_lst->flags.precision = -1;
	p_lst->flags.point = 0;
	p_lst->flags.asterisk = 0;
	return (1);
}

int			lst_init(t_printf_list **p_lst, const char *str)
{
	*p_lst = malloc(sizeof(t_printf_list));
	if (!*p_lst)
		return (-1);
	(*p_lst)->i = 0;
	(*p_lst)->printed_chars = 0;
	(*p_lst)->str = str;
	(*p_lst)->conversors = ft_strdup("cspdiuxX%");
	flags_init(*p_lst);
	return (1);
}

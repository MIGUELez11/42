/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:06:53 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/19 23:29:08 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		writer(t_printf_list *p_lst)
{
	while (p_lst->str[p_lst->i])
	{
		if (p_lst->str[p_lst->i] == '%')
		{
			flags_init(p_lst);
			parser(p_lst);
		}
		else
		{
			write(1, &(p_lst->str[p_lst->i]), 1);
			p_lst->printed_chars += 1;
		}
		p_lst->i++;
	}
	return (1);
}

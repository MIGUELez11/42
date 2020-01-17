/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:06:53 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/17 12:52:46 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		writer(t_printf_list *p_lst)
{
	while (p_lst->str[p_lst->i])
	{
		if (p_lst->str[p_lst->i] == '%')
			parser(p_lst);
		else
		{
			write(1, &(p_lst->str[p_lst->i]), 1);
			p_lst->printed_chars += 1;
		}
		p_lst->i++;
	}
	return (1);
}

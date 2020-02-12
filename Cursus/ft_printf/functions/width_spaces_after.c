/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_spaces_after.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez1 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:43:27 by miguelez1         #+#    #+#             */
/*   Updated: 2020/02/12 09:45:34 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int width_spaces_after(t_printf_list *p_lst, int len)
{
	if (p_lst->flags.minus && p_lst->flags.width > len &&
		p_lst->flags.width > p_lst->flags.precision)
	{
		put_repeated_char(' ', p_lst->flags.width - 
			(p_lst->flags.precision > len ?
				p_lst->flags.precision :
				len));
		p_lst->printed_chars += p_lst->flags.width -
			(p_lst->flags.precision > len ?
				p_lst->flags.precision :
				len); 
	}
	return (1);
}

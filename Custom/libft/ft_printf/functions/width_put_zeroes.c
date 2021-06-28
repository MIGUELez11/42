/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_put_zeroes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:08:50 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/12 19:09:17 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_put_zeroes(t_printf_list *p_lst, int len)
{
	int	print_chars;

	if ((!p_lst->flags.minus && p_lst->flags.width > len
			&& p_lst->flags.precision == -1 && p_lst->flags.zero)
		|| (p_lst->flags.precision > len))
	{
		print_chars = p_lst->flags.width - len;
		if (p_lst->flags.precision != -1)
			print_chars = p_lst->flags.precision - len;
		put_repeated_char('0', print_chars);
		p_lst->printed_chars += print_chars;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:20:45 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/28 20:41:18 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pos_width(t_printf_list *p_lst, int strlen)
{
	if (!p_lst->flags.minus && p_lst->flags.width > 0)
		if (p_lst->flags.width - strlen > 0 && p_lst->flags.precision == -1)
		{
			if (!p_lst->flags.zero)
				put_repeated_char(' ', p_lst->flags.width - strlen);
			else
				put_repeated_char('0', p_lst->flags.width - strlen);
			p_lst->printed_chars += p_lst->flags.width - strlen;
		}
	return (1);
}

int	pos_neg_width(t_printf_list *p_lst, int strlen)
{
	if (p_lst->flags.width < 0)
	{
		p_lst->flags.width *= -1;
		p_lst->flags.minus = 1;
	}
	if (p_lst->flags.minus && p_lst->flags.width > 0)
	{
		if (p_lst->flags.width - strlen > 0 && p_lst->flags.precision == -1)
		{
			if (!p_lst->flags.zero )
				put_repeated_char(' ', p_lst->flags.width - strlen);
			else
				put_repeated_char('0', p_lst->flags.width - strlen);
			p_lst->printed_chars += p_lst->flags.width - strlen;
		}
	}
	return (1);
}

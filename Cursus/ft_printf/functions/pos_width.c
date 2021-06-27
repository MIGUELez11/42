/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:20:45 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/12 19:11:11 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pos_width(t_printf_list *p_lst, int strlen)
{
	if (!p_lst->flags.minus && p_lst->flags.width - strlen > 0)
	{
		if (!p_lst->flags.zero && p_lst->flags.precision == -1)
			put_repeated_char(' ', p_lst->flags.width - strlen);
		else
		{
			if (p_lst->flags.precision == -1)
				put_repeated_char('0', p_lst->flags.width - strlen);
			else if ((p_lst->flags.precision - strlen) > 0)
			{
				put_repeated_char(' ', p_lst->flags.width - strlen);
			}
			else if (!p_lst->flags.zero)
				put_repeated_char(' ', p_lst->flags.width
					- p_lst->flags.precision);
		}
		p_lst->printed_chars += p_lst->flags.width - strlen;
	}
	return (1);
}

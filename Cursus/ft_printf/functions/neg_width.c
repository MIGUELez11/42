/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neg_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:07:52 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/30 16:30:44 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	neg_width(t_printf_list *p_lst, int strlen)
{
	if (p_lst->flags.width < 0)
	{
		p_lst->flags.width *= -1;
		p_lst->flags.minus = 1;// - p_lst->flags.minus;
	}
	if (p_lst->flags.minus && p_lst->flags.width > 0)
	{
		if (p_lst->flags.width - strlen > 0)// && p_lst->flags.precision <= -1)
		{
			put_repeated_char(' ', p_lst->flags.width - strlen);
			p_lst->printed_chars += p_lst->flags.width - strlen;
		}
	}
	return (1);
}

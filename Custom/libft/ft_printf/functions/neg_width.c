/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neg_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:07:52 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/12 19:26:12 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	neg_width(t_printf_list *p_lst, int strlen)
{
	if (p_lst->flags.width < 0)
	{
		p_lst->flags.width *= -1;
		p_lst->flags.minus = 1;
	}
	if (p_lst->flags.minus && p_lst->flags.width > 0)
	{
		if (p_lst->flags.width - strlen > 0)
		{
			put_repeated_char(' ', p_lst->flags.width - strlen);
			p_lst->printed_chars += p_lst->flags.width - strlen;
		}
	}
	return (1);
}

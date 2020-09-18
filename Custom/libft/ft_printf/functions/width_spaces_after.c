/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_spaces_after.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:09:41 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/12 19:11:41 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_spaces_after(t_printf_list *p_lst, int len)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseChar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:54:57 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/28 20:33:44 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_char(t_printf_list *p_lst)
{
	char	c;

	c = (char)va_arg(p_lst->ap, int);
	pos_width(p_lst, 1);
	write(1, &c, 1);
	p_lst->printed_chars += 1;
	pos_neg_width(p_lst, 1);
	return (1);
}

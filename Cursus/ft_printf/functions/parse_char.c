/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseChar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:54:57 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/19 20:27:12 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_char(t_printf_list *p_lst)
{
	char	c;

	c = (char)va_arg(p_lst->ap, int);
	if (!p_lst->flags.minus && p_lst->flags.width > 0)
		put_repeated_char(' ', p_lst->flags.width - 1);
	write(1, &c, 1);
	if (p_lst->flags.minus && p_lst->flags.width > 0)
		put_repeated_char(' ', p_lst->flags.width - 1);
	else if (p_lst->flags.minus || p_lst->flags.width < 0)
		put_repeated_char(' ', -p_lst->flags.width - 1);
	if (p_lst->flags.width > 0)
		p_lst->printed_chars += p_lst->flags.width;
	else if (p_lst->flags.width < 0)
		p_lst->printed_chars -= p_lst->flags.width;
	p_lst->flags.width += 1;

	return (1);
}

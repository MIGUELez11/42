/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:56:09 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/30 17:12:36 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_int(t_printf_list *p_lst)
{
	long int	n;
	int			len;

	n = (long int)va_arg(p_lst->ap, int);
	len = ft_intlen(n); 
	if (!p_lst->flags.zero)
		pos_width(p_lst, (n < 0 ? len + 1 : len));
	if (n < 0)
	{
		write(1, "-", 1);
		p_lst->printed_chars += 1;
	}
	if (p_lst->flags.zero)
		pos_width(p_lst, (n < 0 ? len + 1 : len));
	if (p_lst->flags.precision - len > 0)// && !p_lst->flags.zero)
	{
		put_repeated_char('0', p_lst->flags.precision - len);
		p_lst->printed_chars += p_lst->flags.precision - len;
	}
	putnbr_abs(n, 1);
	p_lst->printed_chars += len;
	neg_width(p_lst, (n < 0 ? len + 1 : len));
	return (1);
}

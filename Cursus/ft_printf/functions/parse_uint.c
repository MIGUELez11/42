/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:56:09 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/09 18:15:16 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_uint(t_printf_list *p_lst)
{
	unsigned int	n;
	int			len;

	n = va_arg(p_lst->ap, unsigned int);
	len = (p_lst->flags.precision == 0 && n == 0 ? 0 : ft_uintlen(n));
	if (p_lst->flags.width < 0)
	{
		p_lst->flags.width *= -1;
		p_lst->flags.minus = 1;
	}
	if (p_lst->flags.width && !p_lst->flags.minus && (!p_lst->flags.zero || p_lst->flags.precision != -1) &&  p_lst->flags.width > len && p_lst->flags.width > p_lst->flags.precision)
	{
		put_repeated_char(' ', p_lst->flags.width - (p_lst->flags.precision > len ? p_lst->flags.precision : len));
		p_lst->printed_chars += p_lst->flags.width - (p_lst->flags.precision > len ? p_lst->flags.precision : len);
	}
	if((!p_lst->flags.minus && p_lst->flags.width > len && p_lst->flags.precision == -1 && p_lst->flags.zero) || (p_lst->flags.precision > len))
	{
		put_repeated_char('0', (p_lst->flags.precision == -1 ? p_lst->flags.width : p_lst->flags.precision) - len);
		p_lst->printed_chars += (p_lst->flags.precision == -1 ? p_lst->flags.width : p_lst->flags.precision) - len; 
	}
	if (!(p_lst->flags.precision == 0 && n == 0))
	putunbr(n, 1);
	p_lst->printed_chars += len;
	if (p_lst->flags.minus && p_lst->flags.width > len && p_lst->flags.width > p_lst->flags.precision)
	{
		put_repeated_char(' ', p_lst->flags.width - (p_lst->flags.precision > len ? p_lst->flags.precision : len));
		p_lst->printed_chars += p_lst->flags.width - (p_lst->flags.precision > len ? p_lst->flags.precision : len); 
	}
	
	return (1);
}

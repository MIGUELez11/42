/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:56:09 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/20 20:00:33 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_int(t_printf_list *p_lst)
{
	int		n;
	int		len;

	n = va_arg(p_lst->ap, int);
	len = (n >= 0 ? ft_intlen(n) : ft_intlen(n) + 1);
	if (p_lst->flags.width && !p_lst->flags.minus && !p_lst->flags.zero)
		put_repeated_char(' ', p_lst->flags.width - (p_lst->flags.precision - len));
	if (n < 0)
	{	
		write(1, "-", 1);
		n *= -1;
	}
	if (p_lst->flags.precision)
		put_repeated_char('0', p_lst->flags.precision - len);
	ft_putnbr_fd(n, 1);
	return (1);
}

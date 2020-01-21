/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:56:09 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/21 10:13:06 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_int(t_printf_list *p_lst)
{
	long int	n;
	int			len;

	n = va_arg(p_lst->ap, int);
	len = ft_intlen(n); 
	
	if (p_lst->flags.width > 0 && !p_lst->flags.minus)
	{
		put_repeated_char((p_lst->flags.zero ? '0' : ' '), p_lst->flags.width
			- (len < p_lst->flags.precision ? p_lst->flags.precision : len)
			- (n < 0 ? 1 : 0));
		p_lst->printed_chars += p_lst->flags.width
		- (len < p_lst->flags.precision ? p_lst->flags.precision : len)
		- (n < 0 ? 1 : 0);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		p_lst->printed_chars += 1;
	}
	if (p_lst->flags.precision >= 0)
	{
		put_repeated_char('0', p_lst->flags.precision - len);
		p_lst->printed_chars += p_lst->flags.precision - len;
	}
	ft_putnbr_fd((n < 0 ? -n : n), 1);
	p_lst->printed_chars += len;
	if (p_lst->flags.width > 0 && p_lst->flags.minus)
	{
		put_repeated_char(' ', p_lst->flags.width - len - (n < 0 ? 1 : 0));
		p_lst->printed_chars += p_lst->flags.width - len - (n < 0 ? 1 : 0);
	}
	else if (p_lst->flags.width < 0 && !p_lst->flags.minus)
	{
		put_repeated_char(' ', -p_lst->flags.width - len);
		p_lst->printed_chars += -p_lst->flags.width - len;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:56:09 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/12 19:27:13 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_int(t_printf_list *p_lst)
{
	long int	n;
	int			len;

	n = va_arg(p_lst->ap, int);
	len = (p_lst->flags.precision == 0 && n == 0 ? 0 : ft_intlen(n));
	if (p_lst->flags.width < 0)
	{
		p_lst->flags.width *= -1;
		p_lst->flags.minus = 1;
	}
	if (n < 0 && p_lst->flags.width > 0)
		p_lst->flags.width--;
	width_spaces_before(p_lst, len);
	if (n < 0)
	{
		write(1, "-", 1);
		p_lst->printed_chars += 1;
	}
	width_put_zeroes(p_lst, len);
	if (!(p_lst->flags.precision == 0 && n == 0))
		putnbr_abs(n, 1);
	p_lst->printed_chars += len;
	width_spaces_after(p_lst, len);
	return (1);
}

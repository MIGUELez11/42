/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:56:09 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/12 19:07:29 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_uint(t_printf_list *p_lst)
{
	unsigned int	n;
	int				len;

	n = va_arg(p_lst->ap, unsigned int);
	len = 0;
	if (!(p_lst->flags.precision == 0 && n == 0))
		len = ft_uintlen(n);
	if (p_lst->flags.width < 0)
	{
		p_lst->flags.width *= -1;
		p_lst->flags.minus = 1;
	}
	width_spaces_before(p_lst, len);
	width_put_zeroes(p_lst, len);
	if (!(p_lst->flags.precision == 0 && n == 0))
		putunbr(n, 1);
	p_lst->printed_chars += len;
	width_spaces_after(p_lst, len);
	return (1);
}

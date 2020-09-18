/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_poin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:32:14 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/17 17:05:42 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_poin(t_printf_list *p_lst)
{
	unsigned long int	n;
	long int			len;
	char				*num;

	n = va_arg(p_lst->ap, unsigned long int);
	num = ft_itoh(n);
	len = (p_lst->flags.precision == 0 && n == 0 ? 2 : ft_strlen(num) + 2);
	if (p_lst->flags.width < 0)
	{
		p_lst->flags.width *= -1;
		p_lst->flags.minus = 1;
	}
	width_spaces_before(p_lst, len);
	p_lst->printed_chars += write(1, "0x", 2);
	if (p_lst->flags.precision != -1)
		p_lst->flags.precision += 2;
	width_put_zeroes(p_lst, len);
	if (p_lst->flags.precision != -1)
		p_lst->flags.precision -= 2;
	if (!(p_lst->flags.precision == 0 && n == 0))
		ft_putstr_fd(num, 1);
	free(num);
	p_lst->printed_chars += len - 2;
	width_spaces_after(p_lst, len);
	return (1);
}

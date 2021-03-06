/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:56:09 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/12 19:25:48 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_lhex(t_printf_list *p_lst)
{
	long int	n;
	int			len;
	char		*num;

	n = va_arg(p_lst->ap, unsigned int);
	num = ft_itoh(n);
	len = (p_lst->flags.precision == 0 && n == 0 ? 0 : ft_strlen(num));
	if (p_lst->flags.width < 0)
	{
		p_lst->flags.width *= -1;
		p_lst->flags.minus = 1;
	}
	width_spaces_before(p_lst, len);
	width_put_zeroes(p_lst, len);
	if (!(p_lst->flags.precision == 0 && n == 0))
		ft_putstr_fd(num, 1);
	free(num);
	p_lst->printed_chars += len;
	width_spaces_after(p_lst, len);
	return (1);
}

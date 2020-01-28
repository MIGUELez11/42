/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez1 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:10:23 by miguelez1         #+#    #+#             */
/*   Updated: 2020/01/28 19:41:12 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_string(t_printf_list *p_lst)
{
	int		i;
	char	*str;
	int		strlen;

	str = va_arg(p_lst->ap, char*);
	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	/*if (p_lst->flags.point && p_lst->flags.precision < 0)
		p_lst->flags.precision = 0;*/
	/*if (p_lst->flags.precision < strlen && p_lst->flags.precision >= 0)
		strlen = p_lst->flags.precision;*/
	i = 0;
	pos_width(p_lst, strlen);
	/*if (!p_lst->flags.minus && p_lst->flags.width > 0)
		put_repeated_char(' ', p_lst->flags.width - strlen);*/
	write(1, &str[i], strlen);
	/*if (p_lst->flags.minus && p_lst->flags.width > 0)
		put_repeated_char(' ', p_lst->flags.width - strlen);
	else if (p_lst->flags.minus || p_lst->flags.width < 0)
		put_repeated_char(' ', -p_lst->flags.width - strlen);*/
	/*if (p_lst->flags.width > 0 && strlen < p_lst->flags.width)
		strlen = p_lst->flags.width;
	else if (p_lst->flags.width < 0 && strlen < -p_lst->flags.width)
		strlen = -p_lst->flags.width;*/
	pos_neg_width(p_lst, strlen);
	p_lst->printed_chars += strlen;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez1 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:10:23 by miguelez1         #+#    #+#             */
/*   Updated: 2020/01/29 18:06:17 by mflorido         ###   ########.fr       */
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
	if (p_lst->flags.precision < strlen && p_lst->flags.precision >= 0)
		strlen = p_lst->flags.precision;
	i = 0;
	pos_width(p_lst, strlen);
	write(1, &str[i], strlen);
	neg_width(p_lst, strlen);
	p_lst->printed_chars += strlen;
	return (1);
}

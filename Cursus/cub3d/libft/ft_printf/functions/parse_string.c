/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:10:23 by miguelez1         #+#    #+#             */
/*   Updated: 2020/10/03 18:54:38 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_string(t_printf_list *p_lst)
{
	int		i;
	char	*str;
	int		strlen;

	i = 0;
	if (!(str = va_arg(p_lst->ap, char*)))
		str = "(null)";
	strlen = ft_strlen(str);
	pos_precision(p_lst, &strlen);
	pos_width(p_lst, strlen);
	write(1, &str[i], strlen);
	neg_width(p_lst, strlen);
	p_lst->printed_chars += strlen;
	return (1);
}

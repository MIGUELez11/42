/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez1 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:10:23 by miguelez1         #+#    #+#             */
/*   Updated: 2020/02/03 20:45:53 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_string(t_printf_list *p_lst)
{
	int		i;
	char	*str;
	int		strlen;

	i = 0;
	str = va_arg(p_lst->ap, char *);
	if (!str)
		str = ft_strdup("(null)");
	strlen = ft_strlen(str);
	pos_precision(p_lst, &strlen);
	pos_width(p_lst, strlen);
	write(1, &str[i], strlen);
	neg_width(p_lst, strlen);
	p_lst->printed_chars += strlen;
	return (1);
}

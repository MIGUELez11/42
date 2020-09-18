/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:00:43 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/21 10:14:38 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_percent(t_printf_list *p_lst)
{
	char	c;
	char	fill;

	c = '%';
	fill = (p_lst->flags.zero ? '0' : ' ');
	if (!p_lst->flags.minus && p_lst->flags.width > 0)
		put_repeated_char(fill, p_lst->flags.width - 1);
	write(1, &c, 1);
	if (p_lst->flags.minus && p_lst->flags.width > 0)
		put_repeated_char(' ', p_lst->flags.width - 1);
	else if (p_lst->flags.minus || p_lst->flags.width < 0)
		put_repeated_char(' ', -p_lst->flags.width - 1);
	p_lst->printed_chars += 1;
	if (p_lst->flags.width > 0)
		p_lst->printed_chars += p_lst->flags.width - 1;
	else if (p_lst->flags.width < 0)
		p_lst->printed_chars -= p_lst->flags.width + 1;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez1 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:10:23 by miguelez1         #+#    #+#             */
/*   Updated: 2020/01/19 20:26:44 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_string(t_printf_list *p_lst)
{
	int		i;
	char	*str;
	int		strlen;

	str = va_arg(p_lst->ap, char*);
	strlen = ft_strlen(str);
	i = 0;
	if (!p_lst->flags.minus && p_lst->flags.width > 0)
		put_repeated_char(' ', p_lst->flags.width - strlen);
	write(1, &str[i], strlen);
	if (p_lst->flags.minus && p_lst->flags.width > 0)
		put_repeated_char(' ', p_lst->flags.width - strlen);
	else if (p_lst->flags.minus || p_lst->flags.width < 0)
		put_repeated_char(' ', -p_lst->flags.width - strlen);

	return (1);
}

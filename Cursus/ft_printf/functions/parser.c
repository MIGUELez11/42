/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez1 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:41:52 by miguelez1         #+#    #+#             */
/*   Updated: 2020/01/08 19:54:30 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_parser(const char *str, int *iadd, va_list ap)
{
	int i;

	i = *iadd + 1;
	if (str[i] == 'c')
		pf_putchar(ap);
	else if (str[i] == '%')
		write(1, "%", 1);
	else if (str[i] == 's')
		pf_putstr(ap);
	i++;
	*iadd = i;
}

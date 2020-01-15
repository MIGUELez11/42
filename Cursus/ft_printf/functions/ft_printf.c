/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:14:24 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/15 08:19:40 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_printf_list	*p_lst;

	lst_init(&p_lst, str);
	va_start(p_lst->ap, str);
	parser(p_lst);
	va_end(p_lst->ap);
	return (p_lst->printedChars);
}

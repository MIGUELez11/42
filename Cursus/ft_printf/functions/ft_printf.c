/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:14:24 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/20 13:48:32 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_printf_list	*p_lst;

	if (!str)
		return (-1);
	if (lst_init(&p_lst, str) == -1)
		return (0);
	va_start(p_lst->ap, str);
	writer(p_lst);
	va_end(p_lst->ap);
	return (p_lst->printed_chars);
}

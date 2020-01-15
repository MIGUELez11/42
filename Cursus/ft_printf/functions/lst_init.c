/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 08:06:26 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/15 08:17:34 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lst_init(t_printf_list **p_lst, const char *str)
{
	*p_lst = malloc(sizeof(t_printf_list));
	if (!*p_lst)
		return (-1);
	(*p_lst)->i = 0;
	(*p_lst)->printedChars = 0;
	(*p_lst)->str = str;
	return (1);
}

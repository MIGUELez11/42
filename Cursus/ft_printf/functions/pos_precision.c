/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:21:01 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/12 19:18:48 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pos_precision(t_printf_list *p_lst, int *strlen)
{
	if (p_lst->flags.precision < *strlen && p_lst->flags.precision >= 0)
		*strlen = p_lst->flags.precision;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:20:45 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/28 09:56:00 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pos_width(t_printf_list *p_lst, int strlen)
{
	if (p_lst->flags.point && p_lst->flags.precision < 0)
		p_lst->flags.precision = 0;
	return (1);
}

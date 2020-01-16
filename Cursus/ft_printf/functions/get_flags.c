/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getFlags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:21:41 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/16 20:03:11 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flags(t_printf_list *p_lst)
{
	while (!ft_strchr(p_lst->conversors, p_lst->str[++p_lst->i]))
	{
		if (p_lst->str[p_lst->i] == '-')
			p_lst->flags.minus = 1;
		else if (p_lst->str[p_lst->i] == '.')
			p_lst->flags.point = 1;
		else if (p_lst->str[p_lst->i] == '*')
			p_lst->flags.asterisk = 1;
	}
	return (1);
}

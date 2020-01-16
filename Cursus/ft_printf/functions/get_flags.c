/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getFlags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:21:41 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/16 10:44:21 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flags(t_printf_list *p_lst)
{
	while (!ft_strchr(p_lst->str[p_lst->i], p_lst->conversors))
	{
		if (p_lst->str[p_lst->i] == '-')
			p_lst->flags->minus = 1;
		else if (p_lst->str[p_lst->i] == '.')
			p_lst->flags->point = 1;
		else if (p_lst->str[p_lst->i] == '*')
			p_lst->flagsd->asterix = 1;

		p_lst->i++;
	}
	return (1);
}

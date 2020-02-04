/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:23:12 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/04 20:47:22 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void free_node(t_printf_list **p_lst)
{
	if ((*p_lst)->conversors)
		free((*p_lst)->conversors);
	if (*p_lst)
		free(*p_lst);
}

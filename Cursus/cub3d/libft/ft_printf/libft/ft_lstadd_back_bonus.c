/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:20:16 by mflorido          #+#    #+#             */
/*   Updated: 2020/09/03 21:14:55 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (new != NULL && alst[0] != NULL)
		ft_lstlast(alst[0])->next = new;
	else if (alst[0] == NULL)
		alst[0] = new;
}

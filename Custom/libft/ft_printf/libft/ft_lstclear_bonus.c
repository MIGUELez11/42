/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:38:26 by mflorido          #+#    #+#             */
/*   Updated: 2020/09/03 21:14:56 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	int		i;
	int		size;
	t_list	*aux;

	i = 0;
	size = ft_lstsize(*lst);
	while (i < size && *lst)
	{
		aux = (*lst)->next;
		del((*lst)->content);
		if (*lst != NULL)
		{
			free(*lst);
		}
		*lst = aux;
	}
	lst = NULL;
}

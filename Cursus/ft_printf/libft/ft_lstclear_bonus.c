/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:38:26 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:55:08 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

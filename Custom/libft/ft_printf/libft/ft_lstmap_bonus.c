/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:47:48 by mflorido          #+#    #+#             */
/*   Updated: 2020/09/03 21:14:56 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rlst;
	t_list	*nlst;

	rlst = malloc(sizeof(t_list) * 1);
	if (!rlst)
		return (NULL);
	nlst = rlst;
	while (lst)
	{
		if (!nlst)
			nlst = malloc(sizeof(t_list *) * 1);
		if (!nlst)
		{
			ft_lstclear(&rlst, del);
			return (NULL);
		}
		nlst->content = f(lst->content);
		lst = lst->next;
		nlst->next = malloc(1 * sizeof(t_list *));
		nlst = nlst->next;
	}
	return (rlst);
}

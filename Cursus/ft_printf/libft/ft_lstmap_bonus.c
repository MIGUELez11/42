/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:47:48 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/23 13:34:20 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

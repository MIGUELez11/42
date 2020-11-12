/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez11 <miguelez11@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:51:53 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/31 11:16:57 by miguelez11       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*newl;

	newl = ft_calloc(1, sizeof(t_list));
	if (newl == NULL)
		return (NULL);
	if (content == NULL)
		newl->content = NULL;
	else
		newl->content = (void *)content;
	newl->next = NULL;
	return (newl);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:51:53 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/18 22:44:30 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*newl;

	newl = ft_calloc(1, sizeof(t_list *));
	if (newl == NULL)
		return (NULL);
	if (content == NULL)
		newl->content = NULL;
	else
		newl->content = (void *)content;
	newl->next = NULL;
	return (newl);
}

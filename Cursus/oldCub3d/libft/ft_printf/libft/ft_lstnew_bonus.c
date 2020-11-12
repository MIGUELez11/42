/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:51:53 by mflorido          #+#    #+#             */
/*   Updated: 2020/09/03 21:14:56 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*newl;

	newl = malloc(1 * sizeof(t_list *));
	if (newl == NULL)
		return (NULL);
	if (content == NULL)
		newl->content = NULL;
	else
		newl->content = (void *)content;
	newl->next = NULL;
	return (newl);
}

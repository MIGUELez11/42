/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:14:24 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/28 19:28:46 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	ft_printf(Main string with conversors, arguments to be printed)
**
**	Conversors:
**		%c	->	print char
**		%s	->	printf string
**		%p	->	print pointer direction
**		%d	->	print int
**		%i	->	print int
**		%u	->	print unsigned int
**		%x	->	print number in hexadecimal in lowercase
**		%X	->	print number in hexadecimal in uppercase
**		%%	->	print '%' char
**
**	Modifiers:
**		-	->	only works if w is established. Justifies left to right.
**		w	->	(1 - max int) left spaces. Justifies right to left.
**		p	->	(. + 1 - max int) it defines float precisions.
**		*	->	replaces w and p with argument value
**		0	->	replaces w spaces with 0
**
**	Example:
**		ft_printf("Hola %6s %0.5d %-6s", "que", 42, "tal");
**		Output: "Hola    que 00042 tal   "
**
*/

int		ft_printf(const char *str, ...)
{
	t_printf_list	*p_lst;

	if (!str)
		return (-1);
	if (lst_init(&p_lst, str) == -1)
		return (0);
	va_start(p_lst->ap, str);
	writer(p_lst);
	va_end(p_lst->ap);
	return (p_lst->printed_chars);
}

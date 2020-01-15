/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:11:11 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/15 08:19:50 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_printf_list {
	va_list		ap;
	int			printedChars;
	int			i;
	const char	*str;
}				t_printf_list;

int				ft_printf(const char *str, ...);
int				lst_init(t_printf_list **p_lst, const char *str);
int				parser(t_printf_list *p_lst);

#endif

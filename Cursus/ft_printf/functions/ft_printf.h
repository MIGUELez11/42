/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:11:11 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/16 19:48:21 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>



typedef struct	s_flags {
	char		minus;
	int			width;
	int			precision;
	char		point;
	char		asterisk;

}				t_flags;

typedef struct	s_printf_list {
	char		*conversors;
	va_list		ap;
	int			printed_chars;
	int			i;
	t_flags		flags;
	const char	*str;
}				t_printf_list;

int				ft_printf(const char *str, ...);
int				lst_init(t_printf_list **p_lst, const char *str);
int				writer(t_printf_list *p_lst);
int				parser(t_printf_list *p_lst);
int				parse_char(t_printf_list *p_lst);
int				parse_flags(t_printf_list *p_lst);

#endif

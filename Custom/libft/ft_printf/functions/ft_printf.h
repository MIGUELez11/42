/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:04:10 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/12 21:00:45 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

/*
**	type: t_flags
**
**	used to set which flags are set
**
**	minus		->	(0 - 1)
**	width		->	(1 - max long int)
**	precision	->	(0 - max long int)
**	point		->	(0 - 1)
**	asterisk	->	(0 - 1)
**	zero		->	(0 - 1)
*/

typedef struct s_flags {
	char		minus;
	int			width;
	int			precision;
	char		point;
	char		asterisk;
	char		zero;

}				t_flags;

/*
**	type: t_printf_list
**
**	used to
**
**	conversors		->	a string with the allowed conversors
**	ap				->	the ap_list
**	printed_chars	->	the number of printed chars
**	i				->	the current position on the main string
**	flags			->	the flag structure
**	str				->	the main string passed
*/

typedef struct s_printf_list {
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
int				parse_flags(t_printf_list *p_lst);
int				parser(t_printf_list *p_lst);
int				parse_char(t_printf_list *p_lst);
int				parse_percent(t_printf_list *p_lst);
int				parse_string(t_printf_list *p_lst);
int				parse_int(t_printf_list *p_lst);
int				parse_uint(t_printf_list *p_lst);
int				parse_uhex(t_printf_list *p_lst);
int				parse_lhex(t_printf_list *p_lst);
int				parse_poin(t_printf_list *p_lst);
int				put_repeated_char(int c, int n);
int				flags_init(t_printf_list *p_lst);
int				pos_width(t_printf_list *p_lst, int strlen);
int				neg_width(t_printf_list *p_lst, int strlen);
int				pos_precision(t_printf_list *p_lst, int *strlen);
void			putnbr_abs(int n, int fd);
void			putunbr(unsigned int n, int fd);
int				ft_uintlen(unsigned int n);
void			free_node(t_printf_list **p_lst);
int				width_spaces_before(t_printf_list *p_lst, int len);
int				width_put_zeroes(t_printf_list *p_lst, int len);
int				width_spaces_after(t_printf_list *p_lst, int len);

#endif

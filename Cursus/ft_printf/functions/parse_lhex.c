/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:56:09 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/11 21:20:23 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int		parse_lhex(t_printf_list *p_lst)
{
	long int	n;
	int			len;
	char		*num;

	n = va_arg(p_lst->ap, unsigned int);
	num = ft_itoh(n);
	len = (p_lst->flags.precision == 0 && n == 0 ? 0 : ft_strlen(num));
	if (p_lst->flags.width < 0)
	{
		p_lst->flags.width *= -1;
		p_lst->flags.minus = 1;
	}
	if (p_lst->flags.width && !p_lst->flags.minus && (!p_lst->flags.zero || p_lst->flags.precision != -1) &&  p_lst->flags.width > len && p_lst->flags.width > p_lst->flags.precision)
	{
		put_repeated_char(' ', p_lst->flags.width - (p_lst->flags.precision > len ? p_lst->flags.precision : len));
		p_lst->printed_chars += p_lst->flags.width - (p_lst->flags.precision > len ? p_lst->flags.precision : len);
	}
	//
	if((!p_lst->flags.minus && p_lst->flags.width > len && p_lst->flags.precision == -1 && p_lst->flags.zero) || (p_lst->flags.precision > len))
	{
		put_repeated_char('0', (p_lst->flags.precision == -1 ? p_lst->flags.width : p_lst->flags.precision) - len);
		p_lst->printed_chars += (p_lst->flags.precision == -1 ? p_lst->flags.width : p_lst->flags.precision) - len; 
	}
	if (!(p_lst->flags.precision == 0 && n == 0))
		ft_putstr_fd(num, 1);
	free(num);
	p_lst->printed_chars += len;
	
	if (p_lst->flags.minus && p_lst->flags.width > len && p_lst->flags.width > p_lst->flags.precision)
	{
		put_repeated_char(' ', p_lst->flags.width - (p_lst->flags.precision > len ? p_lst->flags.precision : len));
		p_lst->printed_chars += p_lst->flags.width - (p_lst->flags.precision > len ? p_lst->flags.precision : len); 
	}
	
	return (1);
}

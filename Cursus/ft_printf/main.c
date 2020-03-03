/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:50:53 by mflorido          #+#    #+#             */
/*   Updated: 2020/02/05 17:01:37 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions/ft_printf.h"

int	ft_printf(const char *str, ...);

int main()
{
	ft_printf("%");
	ft_printf("%5");
	ft_printf("%05");
	ft_printf("%-05");
	ft_printf("%-5");
	ft_printf("%c", 'a');
}

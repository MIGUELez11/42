/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:50:53 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/15 08:22:58 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions/ft_printf.h"

int main()
{
	printf("hola que tal estas?\n");
	printf("hola %c\n", 'M');
	printf("hola %c %c\n", 'M', 'i');
	ft_printf("Hola");
//	ft_printf("hola que tal estas?\n");
//	ft_printf("hola %c\n", 'M');
//	ft_printf("hola %c %c\n", 'M', 'i');
}

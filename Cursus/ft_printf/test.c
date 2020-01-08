/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:35:44 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/08 19:56:51 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "functions/ft_printf.h"

int main()
{
	ft_printf("Hoola que tal estas? %c %s %c %%\n", 'a', "hoola", 'b');
	printf("Hoola que tal estas? %c %s %c %%\n", 'a', "hoola", 'b');
	return (0);
}



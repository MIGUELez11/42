/*  */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 14:30:29 by mflorido          #+#    #+#             */
/*   Updated: 2020/09/20 16:36:35 by mflorido         ###   ########.fr       */
/*                                                                            */
/*  */

#include "cub3d.h"


 int	cb_mainLoop(t_args *args)
 {
 	static unsigned int frame = 0;
 	if (frame == 0)
 	{
 	}
 	if (frame % 60 == 0)
 	{
 		mlx_mouse_move(args->window, args->windowP.x/2, args->windowP.y/2);
 		args++;
 	}
 	frame++;
 	return (1);
 }
 int	endGame(t_args *args)
 {
 	ft_printf("game ended");
 	if (args->mlx && args->window)
 	{
 		mlx_destroy_window(args->mlx, args->window);
 //		free(args->mlx);
 //		args->mlx = 0;
 		args->window = 0;
 		exit(0);
 	}
 	return (1);
 }

 int	cb_onMouseMovement(int x, int y, t_args *args)
 {
 	args++;
 	printf("mouse_x = 5 mouse_x%4d, mouse_y = %4d\n", x, y);
 	return (1);
 }


 int main()
 {
 	t_args	args;

 	args.windowP.x = 500;
 	args.windowP.y = 500;
 	strcpy(args.windowP.name, "Cub3d");
 	args.KeyPress = cb_onKeypress;
 	args.KeyRelease = cb_onKeyrelease;
 	args.MouseMove = cb_onMouseMovement;
 	args.Exit = endGame;
 	args.Main = cb_mainLoop;
 	mf_start(&args);
 }
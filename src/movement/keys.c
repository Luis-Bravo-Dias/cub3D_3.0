/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:29:17 by nvideira          #+#    #+#             */
/*   Updated: 2023/07/13 15:46:15 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_close(void)
{
	mlx_destroy_window(vars()->mlx, vars()->window);
	exit(0);
	return (0);
}

void	test_key(int keycode)
{
	if (keycode == D_KEY)
	{
		if (vars()->key->d)
			printf("D key pressed\n");
		else
			printf("D key released\n");
	}
	else if (keycode == A_KEY)
	{
		if (vars()->key->a)
			printf("A key pressed\n");
		else
			printf("A key released\n");
	}
	else if (keycode == W_KEY)
	{
		if (vars()->key->w)
			printf("W key pressed\n");
		else
			printf("W key released\n");
	}
	else if (keycode == S_KEY)
	{
		if (vars()->key->s)
			printf("S key pressed\n");
		else
			printf("S key released\n");
	}
	else if (keycode == LEFT_KEY)
	{
		if (vars()->key->left)
			printf("Left key pressed\n");
		else
			printf("Left key released\n");
	}
	else if (keycode == RIGHT_KEY)
	{
		if (vars()->key->right)
			printf("Right key pressed\n");
		else
			printf("Right key released\n");
	}
}

int	key_press(int keycode)
{
	if (keycode == ESC_KEY)
		ft_close();
	else if (keycode == D_KEY)
		vars()->key->d = 1;
	else if (keycode == A_KEY)
		vars()->key->a = 1;
	else if (keycode == W_KEY)
		vars()->key->w = 1;
	else if (keycode == S_KEY)
		vars()->key->s = 1;
	else if (keycode == LEFT_KEY)
		rotate(1);
	else if (keycode == RIGHT_KEY)
		rotate(-1);
	test_key(keycode);
	raycast_main();
	return (0);
}

int	key_release(int keycode)
{
	printf("keycode: %d\n", keycode);
	if (keycode == D_KEY)
		vars()->key->d = 0;
	else if (keycode == A_KEY)
		vars()->key->a = 0;
	else if (keycode == W_KEY)
		vars()->key->w = 0;
	else if (keycode == S_KEY)
		vars()->key->s = 0;
	else if (keycode == LEFT_KEY)
		vars()->key->left = 0;
	else if (keycode == RIGHT_KEY)
		vars()->key->right = 0;
	test_key(keycode);
	return (0);
}

void	rotate(int dir)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars()->play->dir_x;
	if (dir == 1)
		vars()->key->left = 1;
	else if (dir == -1)
		vars()->key->right = 1;
	vars()->play->dir_x = vars()->play->dir_x \
		* cos(dir * vars()->chrono->rot_speed) - vars()->play->dir_y \
		* sin(dir * vars()->chrono->rot_speed);
	vars()->play->dir_y = old_dir_x * sin(dir * vars()->chrono->rot_speed) \
		+ vars()->play->dir_y * cos(dir * vars()->chrono->rot_speed);
	old_plane_x = vars()->play->plane_x;
	vars()->play->plane_x = vars()->play->plane_x \
		* cos(dir * vars()->chrono->rot_speed) - vars()->play->plane_y \
		* sin(dir * vars()->chrono->rot_speed);
	vars()->play->plane_y = old_plane_x * sin(dir * vars()->chrono->rot_speed) \
		+ vars()->play->plane_y * cos(dir * vars()->chrono->rot_speed);
}

void	fps_count(void)
{
	vars()->chrono->old_time = vars()->chrono->time;
	vars()->chrono->time = clock();
	vars()->chrono->frame_time = (double)(vars()->chrono->time \
		- vars()->chrono->old_time) / CLOCKS_PER_SEC;
	vars()->chrono->move_speed = vars()->chrono->frame_time * 8000.0;
	vars()->chrono->rot_speed = vars()->chrono->frame_time * 5000.0;
}

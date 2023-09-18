/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:40:43 by ubuntu            #+#    #+#             */
/*   Updated: 2023/07/13 15:57:44 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_play(double new_dir_x, double new_dir_y)
{
	if (vars()->map[(int)(vars()->play->pos_y)][(int)(vars()->play->pos_x + new_dir_x
 			* vars()->chrono->move_speed)] == '0')
		vars()->play->pos_x += new_dir_x * vars()->chrono->move_speed;
	if (vars()->map[(int)(vars()->play->pos_y + new_dir_y * vars()->chrono->move_speed)][(int)(vars()->play->pos_x)] == '0')
		vars()->play->pos_y += new_dir_y * vars()->chrono->move_speed;
}

// w - s , a - d
// M_PI = 180
// M_PI_2 = 90
// M_PI_4 = 45	
double	find_angle(int ws, int ad)
{
	double angle;
	
	if (ws == 1 && ad == 0)
		angle = 0;
	else if (ws == -1 && ad == 0)
		angle = M_PI;
	else if (ws == 0 && ad == 1)
		angle = -M_PI_2;
	else if (ws == 0 && ad == -1)
		angle = M_PI_2;
	else if (ws == 1 && ad == 1)
		angle = -M_PI_4;
	else if (ws == 1 && ad == -1)
		angle = M_PI_4;
	else if (ws == -1 && ad == 1)
		angle = -M_PI_2 - M_PI_4;
	else //if (ws == -1 && ad == -1)
		angle = M_PI_2 + M_PI_4;
	return (angle);
}

void 	lets_move(int ws, int ad)
{
	double	angle;
	double	new_dir_x;
	double	new_dir_y;
	
	if (ws || ad)
	{
		angle = find_angle(ws, ad);
		new_dir_x = vars()->play->dir_x * cos(angle) - vars()->play->dir_y * sin(angle);
		new_dir_y = vars()->play->dir_x * sin(angle) + vars()->play->dir_y * cos(angle);
		move_play(new_dir_x, new_dir_y);
	}
	
}

// void	move_fwd(void)
// {
// 	vars()->key->w = 1;
// 	if (vars()->map[(int)((vars()->play->pos_y))] \
// 			[(int)(vars()->play->pos_x - vars()->play->dir_x \
// 			* vars()->chrono->move_speed)] == '0')
// 		vars()->play->pos_x -= vars()->play->dir_x * vars()->chrono->move_speed;
// 	if (vars()->map[(int)(vars()->play->pos_y + vars()->play->dir_y \
// 			* vars()->chrono->move_speed)][(int)(vars()->play->pos_x)] == '0')
// 		vars()->play->pos_y += vars()->play->dir_y * vars()->chrono->move_speed;
// }

// void	move_bwd(void)
// {
// 	vars()->key->s = 1;
// 	if (vars()->map[(int)((vars()->play->pos_y))] \
// 			[(int)((vars()->play->pos_x + vars()->play->dir_x \
// 			* vars()->chrono->move_speed))] == '0')
// 		vars()->play->pos_x += vars()->play->dir_x * vars()->chrono->move_speed;
// 	if (vars()->map[(int)(vars()->play->pos_y - vars()->play->dir_y \
// 			* vars()->chrono->move_speed)][(int)(vars()->play->pos_x)] == '0')
// 		vars()->play->pos_y -= vars()->play->dir_y * vars()->chrono->move_speed;
// }

// void	move_lsw(void)
// {
// 	vars()->key->a = 1;
// 	if (vars()->map[(int)((vars()->play->pos_y))] \
// 			[(int)((vars()->play->pos_x + vars()->play->plane_x \
// 			* vars()->chrono->move_speed))] == '0')
// 		vars()->play->pos_x += vars()->play->plane_x \
// 			* vars()->chrono->move_speed;
// 	if (vars()->map[(int)(vars()->play->pos_y - vars()->play->plane_y \
// 			* vars()->chrono->move_speed)][(int)(vars()->play->pos_x)] == '0')
// 		vars()->play->pos_y -= vars()->play->plane_y \
// 			* vars()->chrono->move_speed;
// }

// void	move_rsw(void)
// {
// 	vars()->key->d = 1;
// 	if (vars()->map[(int)((vars()->play->pos_y))] \
// 			[(int)((vars()->play->pos_x - vars()->play->plane_x \
// 			* vars()->chrono->move_speed))] == '0')
// 		vars()->play->pos_x -= vars()->play->plane_x \
// 			* vars()->chrono->move_speed;
// 	if (vars()->map[(int)(vars()->play->pos_y + vars()->play->plane_y \
// 			* vars()->chrono->move_speed)][(int)(vars()->play->pos_x)] == '0')
// 		vars()->play->pos_y += vars()->play->plane_y \
// 			* vars()->chrono->move_speed;
// }

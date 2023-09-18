/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:17:35 by ubuntu            #+#    #+#             */
/*   Updated: 2023/09/18 17:38:32 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_texture(int x, int side)
{
	vars()->graph->line_height = (int)(WIN_HEI / vars()->play->perp_wall_dist);
	vars()->graph->draw_start = -vars()->graph->line_height / 2 + WIN_HEI / 2;
	if (vars()->graph->draw_start < 0)
		vars()->graph->draw_start = 0;
	vars()->graph->draw_end = vars()->graph->line_height / 2 + WIN_HEI / 2;
	if (vars()->graph->draw_end >= WIN_HEI)
		vars()->graph->draw_end = WIN_HEI - 1;
	if (side == 0)
		vars()->graph->wall_x = vars()->play->pos_y + vars()->play->perp_wall_dist * vars()->play->ray_d_y;
	else
		vars()->graph->wall_x = vars()->play->pos_x + vars()->play->perp_wall_dist * vars()->play->ray_d_x;
	vars()->graph->wall_x -= floor(vars()->graph->wall_x);
	// if (x >= 10 && x <= 20)
	// 	printf("wallX = %f\n", vars()->graph->wall_x);
	// mlx_pixel_put
	// for (int i = 0; i < 128; i++)
	// {
	// 	for (int i2 = 0; i2 < 128; i2++)
	// 	{
	// 		// my_mlx_pixel_put(i, i2, vars()->textures[0][i + i2 * 128]);

	// 		my_mlx_pixel_put(i, i2, vars()->textures[0][1]);
	// 	}	
	// }
	// printf("AAAAAAAA\n");
	// mlx_put_image_to_window(vars()->mlx, vars()->window, vars()->n_img, 0, 0);
	// printf("BBBBBBBBBBBBBBB\n");
	(void)x;
}

void	tex_raycast(int x)
{
	int	hit;
	int	side;

	vars()->play->cam_x = 2 * x / (double)WIN_WID - 1;
	vars()->play->ray_d_x = -vars()->play->dir_x - vars()->play->plane_x \
		* vars()->play->cam_x;
	vars()->play->ray_d_y = vars()->play->dir_y + vars()->play->plane_y \
		* vars()->play->cam_x;
	vars()->play->map_x = (int)vars()->play->pos_x;
	vars()->play->map_y = (int)vars()->play->pos_y;
	if (vars()->play->ray_d_x == 0)
		vars()->play->d_dist_x = DBL_MAX;
	else
		vars()->play->d_dist_x = fabs(1 / vars()->play->ray_d_x);
	if (vars()->play->ray_d_y == 0)
		vars()->play->d_dist_y = DBL_MAX;
	else
		vars()->play->d_dist_y = fabs(1 / vars()->play->ray_d_y);
	hit = 0;
	if (vars()->play->ray_d_x < 0)
	{
		vars()->play->step_x = -1;
		vars()->play->side_dist_x = (vars()->play->pos_x \
			- vars()->play->map_x) * vars()->play->d_dist_x;
	}
	else
	{
		vars()->play->step_x = 1;
		vars()->play->side_dist_x = (vars()->play->map_x + 1.0 \
			- vars()->play->pos_x) * vars()->play->d_dist_x;
	}
	if (vars()->play->ray_d_y < 0)
	{
		vars()->play->step_y = -1;
		vars()->play->side_dist_y = (vars()->play->pos_y \
			- vars()->play->map_y) * vars()->play->d_dist_y;
	}
	else
	{
		vars()->play->step_y = 1;
		vars()->play->side_dist_y = (vars()->play->map_y + 1.0 \
			- vars()->play->pos_y) * vars()->play->d_dist_y;
	}
	while (hit == 0)
	{
		if (vars()->play->side_dist_x < vars()->play->side_dist_y)
		{
			vars()->play->side_dist_x += vars()->play->d_dist_x;
			vars()->play->map_x += vars()->play->step_x;
			side = 0;
		}
		else
		{
			vars()->play->side_dist_y += vars()->play->d_dist_y;
			vars()->play->map_y += vars()->play->step_y;
			side = 1;
		}
		if (vars()->map[vars()->play->map_y][vars()->play->map_x] == '1')
			hit = 1;
	}
	if (side == 0)
		vars()->play->perp_wall_dist = (vars()->play->map_x \
			- vars()->play->pos_x + (1 - vars()->play->step_x) / 2) \
			/ vars()->play->ray_d_x;
	else
		vars()->play->perp_wall_dist = (vars()->play->map_y \
			- vars()->play->pos_y + (1 - vars()->play->step_y) / 2) \
			/ vars()->play->ray_d_y;
	fps_count();
	put_texture(x, side);
}
// void	tex_raycast(int x)
// {
// int	hit;
// 	int	side;

// 	vars()->play->cam_x = 2 * x / (double)WIN_WID - 1;
// 	vars()->play->ray_d_x = -vars()->play->dir_x - vars()->play->plane_x \
// 		* vars()->play->cam_x;
// 	vars()->play->ray_d_y = vars()->play->dir_y + vars()->play->plane_y \
// 		* vars()->play->cam_x;
// 	vars()->play->map_x = (int)vars()->play->pos_x;
// 	vars()->play->map_y = (int)vars()->play->pos_y;
// 	if (vars()->play->ray_d_x == 0)
// 		vars()->play->d_dist_x = DBL_MAX;
// 	else
// 		vars()->play->d_dist_x = fabs(1 / vars()->play->ray_d_x);
// 	if (vars()->play->ray_d_y == 0)
// 		vars()->play->d_dist_y = DBL_MAX;
// 	else
// 		vars()->play->d_dist_y = fabs(1 / vars()->play->ray_d_y);
// 	hit = 0;
// 	if (vars()->play->ray_d_x < 0)
// 	{
// 		vars()->play->step_x = -1;
// 		vars()->play->side_dist_x = (vars()->play->pos_x \
// 			- vars()->play->map_x) * vars()->play->d_dist_x;
// 	}
// 	else
// 	{
// 		vars()->play->step_x = 1;
// 		vars()->play->side_dist_x = (vars()->play->map_x + 1.0 \
// 			- vars()->play->pos_x) * vars()->play->d_dist_x;
// 	}
// 	if (vars()->play->ray_d_y < 0)
// 	{
// 		vars()->play->step_y = -1;
// 		vars()->play->side_dist_y = (vars()->play->pos_y \
// 			- vars()->play->map_y) * vars()->play->d_dist_y;
// 	}
// 	else
// 	{
// 		vars()->play->step_y = 1;
// 		vars()->play->side_dist_y = (vars()->play->map_y + 1.0 \
// 			- vars()->play->pos_y) * vars()->play->d_dist_y;
// 	}
// 	while (hit == 0)
// 	{
// 		if (vars()->play->side_dist_x < vars()->play->side_dist_y)
// 		{
// 			vars()->play->side_dist_x += vars()->play->d_dist_x;
// 			vars()->play->map_x += vars()->play->step_x;
// 			side = 0;
// 		}
// 		else
// 		{
// 			vars()->play->side_dist_y += vars()->play->d_dist_y;
// 			vars()->play->map_y += vars()->play->step_y;
// 			side = 1;
// 		}
// 		if (vars()->map[vars()->play->map_y][vars()->play->map_x] == '1')
// 			hit = 1;
// 	}
// 	if (side == 0)
// 		vars()->play->perp_wall_dist = (vars()->play->map_x \
// 			- vars()->play->pos_x + (1 - vars()->play->step_x) / 2) \
// 			/ vars()->play->ray_d_x;
// 	else
// 		vars()->play->perp_wall_dist = (vars()->play->map_y \
// 			- vars()->play->pos_y + (1 - vars()->play->step_y) / 2) \
// 			/ vars()->play->ray_d_y;
// 	fps_count();
// 	start_draw(x, side);
// }

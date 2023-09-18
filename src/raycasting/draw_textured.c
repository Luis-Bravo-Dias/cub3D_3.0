/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textured.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:31:18 by ubuntu            #+#    #+#             */
/*   Updated: 2023/09/18 17:58:09 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
	unsigned int	get_pixel_color(t_img *data, int x, int y)
{
	// char	*dst;

	return (*(unsigned int*)(data->addr + (y * data->line_length + x * (data->bpp / 8))));
	// *(unsigned int*)dst = color;
}

void	load_tex(t_img *img, int tex)
{
	int	x;
	int	y;


	printf("Getting called %s\n", vars()->tex_path[tex]);
	img->img = mlx_xpm_file_to_image(vars()->mlx, vars()->tex_path[tex], &img->wid, &img->hei);
	printf("opa\n");
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	// mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);

	printf("Viva\n");
	y = -1;
	while (++y < img->hei)
	{
		x = -1;
		while (++x < img->wid)
		{
			// vars()->textures[tex][img->wid * y + x] = get_pixel_color(img, x, y);
			vars()->textures[tex][img->wid * y + x] = img->addr[img->wid * y + x];
		}
	}
	mlx_destroy_image(vars()->mlx, img->img);
}

void	load_walls(t_img *wall, int side) {
	wall->wid = 0;
	wall->hei = 0;
	
	wall->img = mlx_xpm_file_to_image(vars()->mlx, vars()->tex_path[side], &wall->wid, &wall->hei);
	// wall->addr = mlx_get_data_addr(wall->img, &wall->bpp, &wall->line_length, &wall->endian);
}

void	load_imgs(void)
{
	t_img	img;
	int i = 0;

	load_tex(&img, 0);
	printf("ei\n");
	load_tex(&img, 1);
	load_tex(&img, 2);
	load_tex(&img, 3);

	vars()->n_img = malloc(sizeof(t_img));
	load_walls((vars()->n_img), 0);
	// vars()->test = mlx_xpm_file_to_image(vars()->mlx, vars()->tex_path[0], &i, &i);
	printf("texture height = %d\n", i);
	
	// vars()->n_img = mlx_xpm_file_to_image(vars()->mlx,
	// 	vars()->no,	&vars()->n_img->wid, &vars()->n_img->hei);
	// printf("north: %s\n", vars()->no);
	// vars()->n_img->addr = (int *)mlx_get_data_addr(vars()->n_img->img,
	// 	&vars()->n_img->bits_per_pixel, &vars()->n_img->line_length,
	// 	&vars()->n_img->endian);
	// vars()->w_img = mlx_xpm_file_to_image(vars()->mlx,
	// 	vars()->we,	&vars()->w_img->wid, &vars()->w_img->hei);
	// vars()->w_img->addr = (int *)mlx_get_data_addr(vars()->w_img->img,
	// 	&vars()->w_img->bits_per_pixel, &vars()->w_img->line_length,
	// 	&vars()->w_img->endian);
	// vars()->e_img = mlx_xpm_file_to_image(vars()->mlx,
	// 	vars()->ea,	&vars()->e_img->wid, &vars()->e_img->hei);
	// vars()->e_img->addr = (int *)mlx_get_data_addr(vars()->e_img->img,
	// 	&vars()->e_img->bits_per_pixel, &vars()->e_img->line_length,
	// 	&vars()->e_img->endian);
	// vars()->s_img = mlx_xpm_file_to_image(vars()->mlx,
	// 	vars()->so,	&vars()->s_img->wid, &vars()->s_img->hei);
	// vars()->s_img->addr = (int *)mlx_get_data_addr(vars()->s_img->img,
	// 	&vars()->s_img->bits_per_pixel, &vars()->s_img->line_length,
	// 	&vars()->s_img->endian);
}

void	draw_tex(int side)
{
    double	wall_x;
	int		tex_x;
	double	tex_pos;
	int 	y;
	int		tex_y;

	if (side == 0)
		wall_x = vars()->play->pos_y + vars()->play->perp_wall_dist * vars()->play->ray_d_y;
	else
    	wall_x = vars()->play->pos_x + vars()->play->perp_wall_dist * vars()->play->ray_d_x;
	wall_x -= floor(wall_x); 

	tex_x = (int)(wall_x * (double)TEX_RES);
	if(side == 0 && vars()->play->ray_d_x > 0)
		tex_x = TEX_RES - tex_x - 1;
	if(side == 1 && vars()->play->ray_d_y < 0)
		tex_x = TEX_RES - tex_x - 1;
	y = vars()->graph->draw_start;
	vars()->play->step_y = 1.0 * TEX_RES / vars()->graph->line_height;
	tex_pos = (vars()->graph->draw_start - WIN_HEI / 2 + vars()->graph->line_height / 2) * vars()->play->step_y;
	while (y < vars()->graph->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_RES - 1);
		tex_pos += vars()->play->step_y;
		//Uint32 color = texture[texNum][texHeight * texY + texX]; --> nao aplicavel ao nosso programa
		////make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		//if(side == 1) color = (color >> 1) & 8355711;
		//buffer[y][x] = color;
		y++;
	}
}



/*

draw_wall do lucas    |
                      V
void	draw_wall(t_rloop *tudao, t_draw *draw, t_all *all, int y)
{
	draw->tex_y = (int)draw->texpos & (all->tex[tudao->side]->img_height - 1);
	draw->texpos += draw->step;
	draw->color = *(get_img_pixel(&(all->tex[tudao->side]), \
	draw->tex_x, draw->texpos));
	if (tudao->side == NO || tudao->side == SO)
		draw->color = mlx_get_color_value(all->mlx.mlx,
				(int)((draw->color & 0x0000FF) * 0.70)
				| (int)(((draw->color >> 8) & 0x0000FF) * 0.70) << 8
				| (int)((draw->color >> 16) * 0.70) << 16);
	my_mlx_pixel_put(&(all->mlx->img), SCREENW - draw->x - 1, y, draw->color);
}
*/

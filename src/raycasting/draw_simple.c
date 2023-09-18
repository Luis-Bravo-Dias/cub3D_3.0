/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:42:35 by ubuntu            #+#    #+#             */
/*   Updated: 2023/09/18 17:12:58 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	start_draw(int x, int side)
{
	int	color;

	color = DARK_RED;
	vars()->graph->line_height = (int)(WIN_HEI / vars()->play->perp_wall_dist);
	vars()->graph->draw_start = -vars()->graph->line_height / 2 + WIN_HEI / 2;
	if (vars()->graph->draw_start < 0)
		vars()->graph->draw_start = 0;
	vars()->graph->draw_end = vars()->graph->line_height / 2 + WIN_HEI / 2;
	if (vars()->graph->draw_end >= WIN_HEI)
		vars()->graph->draw_end = WIN_HEI - 1;
	if (side == 0)
		color /= 2;
	put_stripe(x, color);
}

void	put_stripe(int x, int color)
{
	int	y;

	y = vars()->graph->draw_start;
	while (y < vars()->graph->draw_end)
	{
		my_mlx_pixel_put(x, y, color);
		y++;
	}
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = vars()->img->addr + (y * vars()->img->line_length + x \
		* (vars()->img->bpp / 8));
	*(unsigned int *)dst = color;
}

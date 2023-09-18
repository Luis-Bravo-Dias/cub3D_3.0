/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:08:21 by lleiria-          #+#    #+#             */
/*   Updated: 2023/09/18 17:58:01 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include <time.h>
# include <math.h>
# include <ctype.h>
# include <limits.h>
# include <float.h>

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define PI 3.14159265358979323846
# define TWO_PI 6.28318530717958647692
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3
# define TEX_HEI 128
# define TEX_WID 128

//screen
//# define FOV_ANGLE PI / 3
# define WIN_WID 1300
# define WIN_HEI 700
# define TILE_SIZE 1024
# define TEX_RES 128

//key codes
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

//color codes
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define YELLOW 0xFFFF00
# define PURPLE 0xFF00FF
# define CYAN 0x00FFFF
# define ORANGE 0xFFA500
# define BROWN 0xA52A2A
# define PINK 0xFFC0CB
# define GREY 0x808080
# define DARK_GREY 0x404040
# define LIGHT_GREY 0xC0C0C0
# define DARK_BLUE 0x0000A0
# define DARK_GREEN 0x008000
# define DARK_RED 0x800000
# define DARK_YELLOW 0x808000
# define DARK_PURPLE 0x800080

typedef struct s_player
{
	double	cam_x;
	double	dir_x;
	double	dir_y;
	double	ray_d_x;
	double	ray_d_y;
	double	side_dist_x;
	double	side_dist_y;
	double	d_dist_x;
	double	d_dist_y;
	int		step_x;
	int		step_y;
	double	plane_x;
	double	plane_y;
	double	pos_x;
	double	pos_y;
	int		map_x;
	int		map_y;
	double	perp_wall_dist;
	int		hit;
	int		side;
}	t_player;

typedef struct s_graph
{
	double	wall_x;
	int	line_height;
	int	draw_start;
	int	draw_end;
}	t_graph;

typedef struct s_img
{
	int		line_height;
	void	*img;
	char	*addr;
	int		bpp;
	int		wid;
	int		hei;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_time
{
	clock_t	time;
	clock_t	old_time;
	double	frame_time;
	double	move_speed;
	double	rot_speed;
}	t_time;

typedef struct s_key
{
	int	d;
	int	a;
	int w;
	int	s;
	int left;
	int	right;
}	t_key;

typedef struct s_input
{
	char		*tex_path[4];
	int			textures[4][TEX_HEI * TEX_WID];
	char		*f;
	char		*c;
	char		**map;
	int			lines;
	void		*mlx;
	void		*window;
	char		st_dir;
	void		*test;
	t_img		*img;
	t_img		*n_img;
	t_img		*s_img;
	t_img		*w_img;
	t_img		*e_img;
	t_img		*floor;
	t_img		*ceiling;
	t_time		*chrono;
	t_player	*play;
	t_graph		*graph;
	t_key		*key;
}	t_input;

/* ____                                               __      
  /\  _`\                                            /\ \__   
  \ \ \L\ \     __     __  __    ___     __      ____\ \ ,_\  
   \ \ ,  /   /'__`\  /\ \/\ \  /'___\ /'__`\   /',__\\ \ \/  
    \ \ \\ \ /\ \L\.\_\ \ \_\ \/\ \__//\ \L\.\_/\__, `\\ \ \_ 
     \ \_\ \_\ \__/.\_\\/`____ \ \____\ \__/.\_\/\____/ \ \__\
      \/_/\/ /\/__/\/_/ `/___/> \/____/\/__/\/_/\/___/   \/__/
                        /\___/                             
                          \/__/                              */

t_input	*vars(void);

//raycast.c
void    raycast_main(void);
void    raycast(int x);

//tex_raycast.c
void	tex_raycast(int x);

//draw_simple.c
void	put_stripe(int x, int color);
void	start_draw(int x, int side);
void	my_mlx_pixel_put(int x, int y, int color);

//draw_textured.c
void	load_imgs(void);
void	draw_tex(int side);
void	load_tex(t_img *img, int tex);

//exit.c
int		msg_error(char *message);
void	free_matrix(char **matrix);
void	free_array(char *str);

//check_map.c
int		check_map(void);

//check_map_utils.c
int		abnormalities(char **map);
int		extreme_lines(char **map, int line);
int		validate(char x, int is_wall);
int		not_solo(void);
void	check_file(char *file);

//sort_data.c
int		sort_data(char *file);
void	find_player(void);
int		is_not_alright(void);

//parsing_utils.c
int		matrix_size(char **matrix);
char	*ft_strdup_cub(const char *s1);
int		file_lines(char *file);

//mlx_init.c
void    init_cub(void);
void    init_vars(void);
void	define_dir_values(void);

//keys.c
int		ft_close(void);
int		key_press(int keycode);
int		key_release(int keycode);
void	rotate(int dir);
void 	lets_move(int ws, int ad);
// void	move_fwd(void);
// void	move_bwd(void);
// void	move_lsw(void);
// void	move_rsw(void);
void	fps_count(void);

#endif

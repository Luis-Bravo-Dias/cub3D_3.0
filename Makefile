# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 12:06:25 by lleiria-          #+#    #+#              #
#    Updated: 2023/09/18 15:00:56 by lleiria-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -g -fsanitize=address
#MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
RM			= rm -f

NAME		=	cub3D

DEPS		=	libft/libft.a get_next_line/get_next_line.a
INCLUDE		=	-I cub3d.h
SRCS_		=	main.c \
				exit.c \
				sort_data.c \
				mlx_init.c\
				movement/keys.c movement/wasd.c \
				raycasting/raycast.c raycasting/draw_simple.c raycasting/draw_textured.c raycasting/tex_raycast.c\
				checks/check_map.c checks/parsing_utils.c checks/check_map_utils.c

SRCS		=	$(addprefix $(_SRC), $(SRCS_))

_OBJ		=	./obj/
_SRC		= 	./src/
OBJS		=	$(patsubst $(_SRC)%.c, $(_OBJ)%.o, $(SRCS))

all:		$(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	
$(NAME): $(DEPS) $(_OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx_Linux -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(DEPS)

#bonus:		$(SRCS_B) $(OBJS_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -o $(NAME_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -c

libft/libft.a:
	make libft.a -C libft

get_next_line/get_next_line.a:
	make get_next_line.a -C get_next_line

$(_OBJ):
	mkdir $@
	mkdir $(_OBJ)checks
	mkdir $(_OBJ)raycasting
	mkdir $(_OBJ)movement

clean:
	make clean -C libft
	make clean -C get_next_line
	$(RM) -r $(_OBJ)

fclean:	clean
	make fclean -C libft
	make fclean -C get_next_line
	$(RM) $(NAME)

re:	fclean all

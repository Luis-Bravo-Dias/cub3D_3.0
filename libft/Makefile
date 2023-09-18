# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 16:17:16 by lleiria-          #+#    #+#              #
#    Updated: 2021/11/10 11:06:25 by lleiria-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_bzero\
ft_calloc\
ft_isalnum\
ft_isalpha\
ft_isascii\
ft_isdigit\
ft_isprint\
ft_memchr\
ft_memcmp\
ft_memcpy\
ft_memmove\
ft_memset\
ft_strchr\
ft_strlcat\
ft_strlcpy\
ft_strlen\
ft_strncmp\
ft_strnstr\
ft_strrchr\
ft_tolower\
ft_toupper\
ft_atoi\
ft_strdup\
ft_substr\
ft_putchar_fd\
ft_putstr_fd\
ft_putnbr_fd\
ft_putendl_fd\
ft_strjoin\
ft_strtrim\
ft_split\
ft_itoa\
ft_striteri\
ft_strmapi\

BONUS = ft_lstnew\
ft_lstadd_front\
ft_lstadd_back\
ft_lstsize\
ft_lstlast\
ft_lstdelone\
ft_lstclear\
ft_lstiter\
ft_lstmap\


CC =gcc
RM =rm -f
CFLAGS = -Wall -Werror -Wextra -I.

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
			ranlib $(NAME)
clean:
	$(RM)	$(SRC:=.o) $(BONUS:=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)
bonus:  $(SRC:=.o)  $(BONUS:=.o)
		ar rc $(NAME) $(SRC:=.o)	$(BONUS:=.o)
		ranlib $(NAME)
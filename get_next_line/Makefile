NAME = get_next_line.a

SRC = get_next_line \
		get_next_line_utils

CC =gcc
RM =rm -f
CFLAGS = -Wall -Werror -Wextra -I.

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
			ranlib $(NAME)
clean:
	$(RM)	$(SRC:=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)
bonus:  $(SRC:=.o) 
		ar rc $(NAME) $(SRC:=.o)
		ranlib $(NAME)
NAME = libftprintf.a

CFLAGS = -c -Werror -Wall -Wextra

SRCS = ft_printf.c \
		ft_functions.c \
		ft_morefunctions.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ): $(SRCS)
	cc $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all
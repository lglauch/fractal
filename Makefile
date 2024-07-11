NAME	:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Ofast
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm libft/libft.a printf/libftprintf.a
SRCS	:= fractol.c build_fractol.c helper.c fractal_create.c formula.c hooks.c colours.c ft_ctod.c
OBJS	:= ${SRCS:.c=.o}

all: clone libmlx $(NAME)

clone:
	@git clone https://github.com/codam-coding-college/MLX42.git || true

libmlx: clone
	@cd $(LIBMLX) && cmake -B build && cmake --build build -j4


%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"
	@make -C printf
	@make -C libft

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C libft clean
	@make -C printf clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@make -C printf fclean
	rm -rf MLX42

re: clean all








# NAME = fractol

# CFLAGS = -c -Werror -Wall -Wextra

# SRCS =

# OBJS = $(SRCS: .c=.o)

# all: $(NAME)
	
# $(NAME): $(OBJ)
# 	cc -o $(NAME) $(OBJS)

# %.o: %.c
# 	cc $(CFLAGS) -o $@ $<

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all
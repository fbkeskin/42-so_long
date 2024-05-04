SRCS =	map_check.c	\
		map_create.c	\
		main.c	\
		error_management.c	\
		map_validity_check.c	\
		graphic_management.c	\
		game.c

OBJS = $(SRCS:.c=.o)
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g -Iheaders/

NAME = so_long

MLX_PATH = lib/minilibx
LIBFT_PATH = lib/libft
FT_PRINTF_PATH = lib/ft_printf
GET_NEXT_LINE_PATH = lib/get_next_line

MLX = libmlx.a
LIBFT = libft.a
FT_PRINTF = libftprintf.a
GET_NEXT_LINE = libftgnl.a

LIBRARY = -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

MLX_ARCH = $(MLX_PATH)/$(MLX)
LIBFT_ARCH = $(LIBFT_PATH)/$(LIBFT)
FT_PRINTF_ARCH = $(FT_PRINTF_PATH)/$(FT_PRINTF)
GET_NEXT_LINE_ARCH = $(GET_NEXT_LINE_PATH)/$(GET_NEXT_LINE)

all: $(NAME)

$(NAME): $(OBJS)
	make -s -C $(MLX_PATH) -j16 2> /dev/null
	make -s -C $(LIBFT_PATH)
	make -s -C $(FT_PRINTF_PATH)
	make -s -C $(GET_NEXT_LINE_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARCH) $(FT_PRINTF_ARCH) $(GET_NEXT_LINE_ARCH) $(LIBRARY) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make -s -C $(LIBFT_PATH) clean
	@make -s -C $(FT_PRINTF_PATH) clean
	@make -s -C $(GET_NEXT_LINE_PATH) clean
	@make -s -C $(MLX_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_PATH) fclean
	@make -s -C $(FT_PRINTF_PATH) fclean
	@make -s -C $(GET_NEXT_LINE_PATH) fclean

re: fclean all

.PHONY: all clean fclean re

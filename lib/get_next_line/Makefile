SRCS =	get_next_line.c \
		get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

NAME = libftgnl.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes
LIBS = ar -rc

SRC_DIR = src
LIBFT_DIR = libft
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIBFT_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

$(NAME): $(OBJS)
	$(LIBS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(SRC_DIR)/*.o $(LIBFT_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

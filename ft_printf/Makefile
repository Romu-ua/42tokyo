cc = CC
# CFLAGS = -Wall -Werror -Wextra -Ift_printf/includes
CFLAGS = -Ift_printf/includes

SRC_DIR = ft_printf/src
LIBFT_DIR = ft_printf/libft
TESTER_DIR = tester_func
INCLUDES = -Ift_printf/includes

MAIN = main.c
SRCS = $(wildcard $(SRC_DIR)/*.c )  $(wildcard $(LIBFT_DIR)/*.c) $(wildcard $(TESTER_DIR)/*.c)
OBJS = $(SRCS:.c=.o) $(MAIN:.c=.o)

TARGET = a.out

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

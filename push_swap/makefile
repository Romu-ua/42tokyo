# CC = clang -fsanitize=address -g
CC = cc

CFLAGS = -Wall -Werror -Wextra
SOURCES = main.c addidx.c check_sorted.c ft_atol.c input_check.c insert_add_head.c list_len.c push.c \
	record_op.c reverse_rotate.c rotate.c simple_sort_sub.c simple_sort.c swap.c threshold_push.c operation.c \
	sort_fix.c

OBJECTS = $(SOURCES:.c=.o)
TARGET = push_swap

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(TARGET)

re: fclean clean

.PHONY: all clean fclean re

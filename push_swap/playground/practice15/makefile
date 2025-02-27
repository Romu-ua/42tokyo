CC = clang -fsanitize=address -g
# CC = cc

CFLAGS = -Wall -Werror -Wextra
SOURCES = case.c half_push.c main.c operation.c push.c record_op.c reverse_rotate.c rotate.c \
			sort_addindex.c swap.c utils.c length_list.c fix.c ft_atol.c input_check.c ft_qsort.c \
			ft_s_printf.c simple_sort.c
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

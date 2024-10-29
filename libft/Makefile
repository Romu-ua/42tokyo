CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_DIR)
SRC_DIR = libft
TEST_DIR = tests
INCLUDES_DIR = includes

TARGETS = test_ft_isalpha test_ft_isdigit test_ft_isalnum test_ft_isascii test_ft_isprint test_ft_strlen test_ft_memset\
		  test_ft_bzero

SRCS_ft_isalpha = $(SRC_DIR)/ft_isalpha.c $(TEST_DIR)/ft_isalpha.c
SRCS_ft_isdigit = $(SRC_DIR)/ft_isdigit.c $(TEST_DIR)/ft_isdigit.c
SRCS_ft_isalnum = $(SRC_DIR)/ft_isalnum.c $(SRC_DIR)/ft_isalpha.c $(SRC_DIR)/ft_isdigit.c $(TEST_DIR)/ft_isalnum.c
SRCS_ft_isascii = $(SRC_DIR)/ft_isascii.c $(TEST_DIR)/ft_isascii.c
SRCS_ft_isprint = $(SRC_DIR)/ft_isprint.c $(TEST_DIR)/ft_isprint.c
SRCS_ft_strlen = $(SRC_DIR)/ft_strlen.c $(TEST_DIR)/ft_strlen.c
SRCS_ft_memset = $(SRC_DIR)/ft_memset.c $(TEST_DIR)/ft_memset.c
SRCS_ft_bzero = $(SRC_DIR)/ft_bzero.c $(TEST_DIR)/ft_bzero.c
# SRCS_ft_isalpha = $(SRC_DIR)/ft_isalpha.c $(TEST_DIR)/ft_isalpha.c 追加していく。

all: $(TARGETS)

test_ft_isalpha: $(SRCS_ft_isalpha)
	$(CC) $(CFLAGS) -o $@ $^

test_ft_isdigit: $(SRCS_ft_isdigit)
	$(CC) $(CFLAGS) -o $@ $^

test_ft_isalnum: $(SRCS_ft_isalnum)
	$(CC) $(CFLAGS) -o $@ $^

test_ft_isascii: $(SRCS_ft_isascii)
	$(CC) $(CFLAGS) -o $@ $^


test_ft_isprint: $(SRCS_ft_isprint)
	$(CC) $(CFLAGS) -o $@ $^

test_ft_strlen: $(SRCS_ft_strlen)
	$(CC) $(CFLAGS) -o $@ $^

test_ft_memset: $(SRCS_ft_memset)
	$(CC) $(CFLAGS) -o $@ $^

test_ft_bzero: $(SRCS_ft_bzero)
	$(CC) $(CFLAGS) -o $@ $^

# test_ft_atoi: $(SRCS_ft_isalpha)
# 	$(CC) $(CFLAGS) -o $@ $^


clean:
	rm -f $(TARGETS)

run_all: $(TARGETS)
	@./run_all.sh

.PHONY: clean

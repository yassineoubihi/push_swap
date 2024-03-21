# Source files
SRCF = main.c \
		libft/ft_split.c \
		libft/ft_isdigit.c \
		libft/ft_isascii.c \
		libft/ft_memcpy.c \
		libft/ft_strjoin.c \
		libft/ft_strsearch.c \
		libft/ft_strcmp.c \
		libft/ft_atoi.c \
		parcing/parcing.c \
		parcing/parcing_utils.c \
		parcing/parcing_utils_2.c \
		parcing/check_space.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_putaddres.c \
		ft_printf/ft_putchar_c.c \
		ft_printf/ft_puthex.c \
		ft_printf/ft_puthex_upp.c \
		ft_printf/ft_putnbr.c \
		ft_printf/ft_putstr.c \
		ft_printf/ft_putunsigned.c \
		libft/ft_strlen.c \
		moves/moves_part_one.c \
		moves/moves_part_two.c \
		moves/moves_last_part.c \
		sorting/sorting_case_one.c \
		sorting/main_algo.c \
		sorting/main_algo_help_1.c \
		sorting/main_algo_help2.c \
		sorting/sorting_case_one_help1.c \
		sorting/sorting_case_one_help2.c

OBJF = $(SRCF:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

PUSH_SWAP = push_swap

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(OBJF)
	$(CC) $(CFLAGS) $(OBJF) -o $(PUSH_SWAP)

%.o: %.c push_swap.h
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJF)

fclean: clean
	$(RM) $(PUSH_SWAP)

re: fclean all

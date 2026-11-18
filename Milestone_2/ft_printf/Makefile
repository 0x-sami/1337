NAME=libftprintf.a

AR=ar -rsc
CC=cc
FLAGS=-Wall -Werror -Wextra

SRCS=ft_printf.c print_utils_hex.c print_utils_nbr.c print_utils_chars.c
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	
%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: all

.PHONY: clean

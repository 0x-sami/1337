NAME=libft.a

CC=cc
AR=ar -rsc

SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all: $(NAME) clean

clean:
	rm -rf $(OBJS)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

.PHONY: clean

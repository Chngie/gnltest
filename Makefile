CC = cc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=10000000

HDRS = ../get_next_line.h
BNSHDRS = ../get_next_line_bonus.h

SRCS = main.c ../get_next_line.c ../get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

BNS = main_bonus.c ../get_next_line_bonus.c ../get_next_line_utils_bonus.c
BNSOBJS = $(BNS:.c=.o)

NAME = test

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BNSOBJS)
	$(CC) $(CFLAGS) $(BNSOBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(BNSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

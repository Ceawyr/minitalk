NAME = server
NAME_CLIENT = client

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = server.c ft_strjoin.c ft_strdup.c ft_putnbr.c ft_memset.c ft_atoi.c ft_strlen.c
SRCS_CLIENT = client.c ft_strjoin.c ft_strdup.c ft_putnbr.c ft_memset.c ft_atoi.c ft_strlen.c

OBJS = $(SRCS:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(NAME) $(NAME_CLIENT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME) $(NAME_CLIENT)

re: fclean all

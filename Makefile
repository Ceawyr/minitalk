NAME = server
NAME_CLIENT = client

NAME_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = server.c ft_strjoin.c ft_strdup.c ft_putnbr.c ft_memset.c ft_atoi.c ft_strlen.c
SRCS_CLIENT = client.c ft_strjoin.c ft_strdup.c ft_putnbr.c ft_memset.c ft_atoi.c ft_strlen.c

OBJS = $(SRCS:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(NAME) $(NAME_CLIENT) $(NAME_BONUS) $(NAME_CLIENT_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME_BONUS): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(OBJS_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME) $(NAME_CLIENT) $(NAME_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

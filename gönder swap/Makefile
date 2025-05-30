NAME = push_swap
BONUS_NAME = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

SRC = push_swap.c \
      action.c \
      action1.c \
      argument.c \
      chunk.c \
      process.c \
      sorted.c \
      stack.c \
      utils.c \
      chunk_size.c

BONUS_SRC = bonus/checker.c \
            bonus/argument_bonus.c \
            bonus/utils_bonus.c \
            bonus/action_bonus.c \
            bonus/read.c \
			bonus/action1_bonus.c \
			bonus/action2_bonus.c \
			bonus/sorted.c \
			bonus/stack_bonus.c \
            bonus/get_next_line/get_next_line.c \
            bonus/get_next_line/get_next_line_utils.c

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C libft

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LIBFT)

clean:
	@$(MAKE) -C libft clean
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: re fclean clean all bonus
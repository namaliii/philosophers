NAME	:= philosophers

CC		:= cc  -fsanitize=address #-fsanitize=thread -g -o
CFLAGS	:= -Wextra -Wall -Werror -pthread

SRCS	:= arg_error_check.c ft_atoi.c initialize.c \
			main.c time.c pick_drop_forks.c routine.c \
			think_sleep_die.c eat.c clean_up.c \
			threads.c

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Philosophers are taking their places around the table..."
	@$(CC) $(OBJS) -pthread -o $(NAME)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "Cleaning the dishes..."
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
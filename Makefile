NAME	:= philosophers

CC		:= cc  #-fsanitize=address
CFLAGS	:= -Wextra -Wall -Werror

SRCS	:= arg_error_check.c ft_atoi.c initialize.c \
			philo.c time.c pick_drop_forks.c routine.c \
			think_sleep_die.c eat.c 

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Philosophers are taking their places around the table..."
	@$(CC) $(OBJS) -o $(NAME)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "Cleaning the dishes..."
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
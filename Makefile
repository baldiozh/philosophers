NAME		= philo

SRC			= philosophers.c \
			  init.c utils.c \
			  ft_atoi.c
OBJ			= $(patsubst %.c,%.o,$(SRC))

CFLAGS		=	-Wall -Werror -Wextra
HEADER	=	philosophers.h


all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			@gcc $(CFLAGS) $(OBJ) -o $(NAME)
			@printf "\x1b[32mPhilo is ready!\n"
			@printf "\x1b[34mEnter number of philosophers, time to die, time to eat, time to sleep:\n"

#-fsanitize=address

%.o : 		%.c
			@gcc $(CFLAGS) -Ofast -c $< -o $@
#-Ofast?

clean:
			@rm -rf $(OBJ)

fclean: 	clean
			@rm -rf $(NAME)

re: 		fclean all

#bonus:		re

.PHONY: 	all clean fclean re

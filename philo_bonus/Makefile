# Name
NAME			= philo_bonus

INCLUDES		= -I$(HEADERS_DIR)

# Header files
HEADERS_DIR		= ./includes_bonus/
HEADERS_LIST	= philosophers_bonus.h
HEADERS			= $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

# Sources
SRC_DIR			= ./src_bonus/
SRC_LIST		= main.c \
				libft_utils.c \
				init.c letsgo.c actions.c utils.c \
				terminate.c
SRC 			= $(addprefix $(SRC_DIR), $(SRC_LIST))

# Objects
OBJ_DIR			= obj/
OBJ_LIST		= $(patsubst %.c, %.o, $(SRC_LIST))
OBJ				= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# Compile
CC 		= gcc
CFLAGS 	= -Wall -Werror -Wextra -g

# Colors
GREEN 	= \x1b[0;32m
RED 	= \x1b[0;31m
RESET 	= \x1b[0m


all: 	$(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) Makefile
		@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
		@echo "$(GREEN)$(NAME) is ready.$(RESET)"

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
		@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
		@echo "$(GREEN).$(RESET)\c"

clean:
		@rm -rf $(OBJ_DIR)
		@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
		@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: 	fclean all

.PHONY: all clean fclean re

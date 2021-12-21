# Name
NAME			= philo

INCLUDES		= -I$(HEADERS_DIR)

# Header files
HEADERS_DIR		= ./includes/
HEADERS_LIST	= philosophers.h
HEADERS			= $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

# Sources
SRC_DIR			= ./src/
#SRC_BONUS_DIR	= ./src_bonus/
SRC_LIST		= philosophers.c \
				ft_atoi.c init.c utils.c actions.c letsgo.c

# SRC_BONUS_LIST = main.c init.c utils.c ft_atoi.c
SRC 			= $(addprefix $(SRC_DIR), $(SRC_LIST))
# SRCS_BONUS = $(addprefix $(SRC_BONUS_DIRECTORY), $(SRC_BONUS_LIST))

# Objects
OBJ_DIR			= obj/
OBJ_LIST		= $(patsubst %.c, %.o, $(SRC_LIST))
OBJ				= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# Compile
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

# Colors
GREEN 	= \x1b[0;32m
RED 	= \x1b[0;31m
RESET 	= \x1b[0m


all: 	$(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) Makefile
		@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
		@echo "$(GREEN)$(NAME) is ready.$(RESET)"
#@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
#@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

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

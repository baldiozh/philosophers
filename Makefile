# Name
NAME		= philo

INCLUDES	= -I$(HEADERS_DIR)

# Header files
HEADERS_DIR		= ./includes/
HEADERS_LIST	= philosophers.h
HEADERS			= $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

# Sources
SRC_DIR			= ./src/
#SRC_BONUS_DIR	= ./src_bonus/
SRC_LIST		= philosophers.c \
				ft_atoi.c init.c utils.c

# SRC_BONUS_LIST = main.c init.c utils.c ft_atoi.c
SRC 			= $(addprefix $(SRC_DIR), $(SRC_LIST))
# SRCS_BONUS = $(addprefix $(SRC_BONUS_DIRECTORY), $(SRC_BONUS_LIST))

# Objects
OBJ_DIR			= obj/
OBJ_LIST	= $(patsubst %.c, %.o, $(SRC_LIST))
OBJ				= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# Compile
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

# Colors
GREEN 	= \033[0;32m
RED 	= \033[0;31m
RESET 	= \033[0m


all: 	$(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) Makefile
		@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
		@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
		@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

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

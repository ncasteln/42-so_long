# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 15:21:33 by ncasteln          #+#    #+#              #
#    Updated: 2023/07/21 09:14:21 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *******************************************************************************
# *																		VARIABLES
# *******************************************************************************
NAME = so_long
CFLAGS = -g -Wall -Wextra -Werror

# ------------------------------------------------------------------------ MYLIB
MYLIB = $(LIBFT) $(FT_PRINTF) $(GNL) $(LIBNC)
MYLIB_DIR = ./lib/mylib/
LIBFT = $(MYLIB_DIR)libft/libft.a
FT_PRINTF = $(MYLIB_DIR)ft_printf/libftprintf.a
GNL = $(MYLIB_DIR)get_next_line/libgnl.a
LIBNC = $(MYLIB_DIR)libnc/libnc.a

# ------------------------------------------------------------------------ MLX42
BREW = /Users/$(USER)/goinfre/.brew/
BREW_ALT = /Users/$(USER)/.brew/
HBREW = /Users/$(USER)/.brewconfig.zsh
ifeq ($(wildcard $(BREW)), )
	BREW = $(BREW_ALT)
endif
ifeq ($(wildcard $(BREW)), )
	BREW = $(HBREW)
endif
GET_HBREW = curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

CMAKE = $(BREW)Cellar/cmake/3.27.0
GLFW = $(BREW)Cellar/glfw/3.3.8/lib/
MLX42 = $(MLX42_DIR)build/libmlx42.a
MLX42_DIR = ./lib/MLX42/

# ------------------------------------------------------------------------- SRCS
VPATH = ./src/:./src_bonus/:./src_valid/
OBJS_DIR = ./objs/
# ------------------------------------------------------------------------- MAND
SRC = main.c \
	init_window.c \
	state_print.c \
	lst_to_dptr.c \
	key_handling.c \
	arg_validation.c \
	map_validation.c \
	move_calc.c \
	path_validation.c \
	map_drawing.c \
	free_all.c \
	display_messages.c \
	exit_err_handling.c
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
OBJS_FLAG = $(OBJS_DIR).mand_flag

# ------------------------------------------------------------------------ BONUS
SRC_BONUS = main_bonus.c \
	init_window_bonus.c \
	state_print_bonus.c \
	lst_to_dptr_bonus.c \
	key_handling_bonus.c \
	arg_validation_bonus.c \
	map_validation_bonus.c \
	move_calc_bonus.c \
	path_validation_bonus.c \
	map_drawing_bonus.c \
	free_all_bonus.c \
	event_handling_bonus.c \
	npc_move_calc_bonus.c \
	display_messages_bonus.c
ifneq ($(filter bonus,$(MAKECMDGOALS)),)
	OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
	OBJS_FLAG = $(OBJS_DIR).bonus_flag
endif

# ------------------------------------------------------------------------ VALID
SRC_VALID = main_valid.c \
	lst_to_dptr_valid.c \
	arg_validation_valid.c \
	map_validation_valid.c \
	path_validation_valid.c \
	free_all_valid.c \
	display_messages_valid.c \
	exit_err_handling_valid.c
ifneq ($(filter valid,$(MAKECMDGOALS)),)
	OBJS = $(addprefix $(OBJS_DIR), $(SRC_VALID:.c=.o))
	OBJS_FLAG = $(OBJS_DIR).valid_flag
endif

# --------------------------------------------------------------------- INCLUDES
INCLUDE = -I ./include/ \
	-I ./lib/mylib/libft/include/ \
	-I ./lib/mylib/ft_printf/include/ \
	-I ./lib/mylib/get_next_line/ \
	-I ./lib/mylib/libnc/include/ \
	-I ./lib/MLX42/include/MLX42/

# *******************************************************************************
# *																			RULES
# *******************************************************************************
all: $(NAME)

bonus: $(NAME)

valid: $(NAME)_valid

$(NAME): $(MYLIB) $(MLX42) $(OBJS) $(OBJS_FLAG)
	@echo "$(NC)Compiling $@ executable file..."
	@$(CC) $(CFLAGS) \
	$(OBJS) $(MYLIB) $(MLX42) \
	-lglfw -L$(GLFW) \
	-o $(NAME)
	@echo "$(GREEN)	$@ successfully compiled!"

$(NAME)_valid: $(MYLIB) $(OBJS) $(OBJS_FLAG)
	@echo "$(NC)Compiling $@ executable file..."
	@$(CC) $(CFLAGS) \
	$(OBJS) $(MYLIB) \
	-o $(NAME)_valid
	@echo "$(GREEN)	$@ successfully compiled!"

$(MYLIB):
	@echo "$(NC)Compiling dependencies..."
	@$(MAKE) -C $(MYLIB_DIR)

# -------------------------------------------------------- MLX42 & DEPENDENCIES
$(MLX42): $(BREW) $(CMAKE) $(GLFW) $(MLX42_DIR)
	@echo "$(NC)Compiling $@..."
	cd $(MLX42_DIR) && cmake -B build
	$(MAKE) -C $(MLX42_DIR)build -j4
$(BREW):
	@echo "$(NC)Getting [42homebrew]"
	@$(GET_HBREW)
$(CMAKE):
	@echo "$(NC)Installing [cmake]"
	@brew install cmake
$(GLFW):
	@echo "$(NC)Installing [glfw]"
	@brew install glfw
$(MLX42_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR)

# --------------------------------------------------------------------- OBJECTS
$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@cc $(CFLAGS) -c $< -o $@ $(INCLUDE)

# [objs_flag] make possible to re-make the exe file alternately between
# 'all' and 'bonus' rule, without clean or fclean them
$(OBJS_FLAG):
	@rm -rf $(OBJS_DIR).mand_flag
	@rm -rf $(OBJS_DIR).bonus_flag
	@rm -rf $(OBJS_DIR).valid_flag
	@mkdir -p $(OBJS_DIR)
	@touch $(OBJS_FLAG)
	@echo "$(YELLOW)	Created [objs_flag]"

# ------------------------------------------------------------------- CLEANING
clean:
	@echo "$(NC)Removing [so_long] objs..."
	@rm -rf $(OBJS_DIR)
	@echo "$(NC)Destroying [mylib] archives..."
	@$(MAKE) fclean -C $(MYLIB_DIR)

fclean_mlx:
	@echo "$(NC)Removing [MLX42]..."
	@rm -rf $(MLX42_DIR)

# Clean every build, included MLX42
fclean: clean
	@echo "$(NC)Removing [MLX42 build folder]..."
	@rm -rf $(MLX42_DIR)build/
	@echo "$(NC)Removing [$(NAME)]..."
	@rm -f $(NAME)
	@echo "$(NC)Removing [$(NAME)_valid]..."
	@rm -f $(NAME)_valid

re: fclean all

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

.PHONY: all clean fclean fclean_mlx re bonus

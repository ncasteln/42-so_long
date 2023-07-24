# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 15:21:33 by ncasteln          #+#    #+#              #
#    Updated: 2023/07/24 16:49:02 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *******************************************************************************
#                                                                       VARIABLES
# *******************************************************************************
NAME = so_long
CFLAGS = -g -Wall -Wextra -Werror

# ------------------------------------------------------------------------ MYLIB
MYLIB = $(LIBFT) $(FT_PRINTF) $(GNL)
MYLIB_DIR = ./lib/mylib/
LIBFT = $(MYLIB_DIR)libft/libft.a
FT_PRINTF = $(MYLIB_DIR)ft_printf/libftprintf.a
GNL = $(MYLIB_DIR)get_next_line/libgnl.a

# ------------------------------------------------------------------------ GLFW
# GLFW = -lglfw -L /Users/$(USER)/goinfre/.brew/opt/glfw/lib/
# GLFW = -lglfw -L/Users/$(USER)/goinfre/.brew/opt/glfw/3.3.8/lib/
GLFW = -lglfw -L/Users/$(USER)/goinfre/.brew/Cellar/glfw/3.3.8/lib/
# GLFW = -lglfw -L/Users/$(USER)/.brew/opt/glfw/lib
# GLFW = -lglfw -L/Users/$(USER)/.brew/Cellar/glfw/lib

# ------------------------------------------------------------------------ MLX42
MLX42 = $(MLX42_DIR)build/libmlx42.a
MLX42_DIR = ./lib/MLX42/

# ------------------------------------------------------------------------- SRCS
VPATH = ./src/:./src_bonus/
OBJS_DIR = ./objs/

# ------------------------------------------------------------------------- MAND
SRC = main.c \
	dptr_op.c \
	init_mlx_elements.c \
	state_print.c \
	key_handling.c \
	arg_validation.c \
	lines_validation.c \
	items_validation.c \
	p_move_calc.c \
	path_validation.c \
	map_drawing.c \
	free_all.c \
	display_messages.c \
	exit_err_handling.c
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
OBJS_FLAG = $(OBJS_DIR).mand_flag

# ------------------------------------------------------------------------ BONUS
SRC_BONUS = main_bonus.c \
	dptr_op_bonus.c \
	init_mlx_elements_bonus.c \
	state_print_bonus.c \
	key_handling_bonus.c \
	arg_validation_bonus.c \
	lines_validation_bonus.c \
	items_validation_bonus.c \
	path_validation_bonus.c \
	map_drawing_bonus.c \
	free_all_bonus.c \
	event_handling_bonus.c \
	p_move_calc_bonus.c \
	n_move_calc_bonus.c \
	display_messages_bonus.c \
	exit_err_handling_bonus.c \
	reset_images_bonus.c \
	possible_move_calc_bonus.c
ifneq ($(filter bonus,$(MAKECMDGOALS)),)
	OBJS = $(addprefix $(OBJS_DIR), $(SRC_BONUS:.c=.o))
	OBJS_FLAG = $(OBJS_DIR).bonus_flag
endif

# --------------------------------------------------------------------- INCLUDES
INCLUDE = -I ./include/ \
	-I ./lib/mylib/libft/include/ \
	-I ./lib/mylib/ft_printf/include/ \
	-I ./lib/mylib/get_next_line/ \
	-I ./lib/mylib/libnc/include/ \
	-I ./lib/MLX42/include/MLX42/ \

# ------------------------------------------------------------------------- LEAKS
# Git repo which traces mem leaks without conflicting with MLX. Explore the link
# to know more about it and leave a star if you find useful!
# 1) add $(LEAK_FINDER_INCLUDE) to the rule which makes objects
# 2) add $(LEAK_FINDER) to the the rule which build the program
# 3) add #include "malloc.h at the top of the main .h file
# 4) add function show_alloc_mem_ex() where you want to monitor the memory
# !!!) Remember to remove if don't needed!
LEAK_FINDER = -L./leak_finder -lft_malloc
LEAK_FINDER_INCLUDE = -I./leak_finder/includes
GET_LEAK_FINDER = git clone https://github.com/iwillenshofer/leak_finder.git leak_finder
GET_LEAK_FINDER_ALT = git clone git@github.com:iwillenshofer/leak_finder.git leak_finder

# *******************************************************************************
#                                                                           RULES
# *******************************************************************************
all: $(NAME)

bonus: $(NAME)

$(NAME): $(MYLIB) $(MLX42) $(OBJS) $(OBJS_FLAG)
	@echo "$(NC)Compiling $@ executable file..."
	@$(CC) $(CFLAGS) \
	$(OBJS) $(MYLIB) $(MLX42) $(GLFW) \
	-o $(NAME)
	@echo "$(G)	$@ successfully compiled!"

$(MYLIB):
	@echo "$(NC)Compiling dependencies..."
	@$(MAKE) -C $(MYLIB_DIR)

# --------------------------------------------------------------------- OBJECTS
$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@cc $(CFLAGS) -c $< -o $@ $(INCLUDE)

# [objs_flag] make possible to re-make the exe file alternately between
# 'all' and 'bonus' rule, without clean or fclean them
$(OBJS_FLAG):
	@rm -rf $(OBJS_DIR).mand_flag
	@rm -rf $(OBJS_DIR).bonus_flag
	@mkdir -p $(OBJS_DIR)
	@touch $(OBJS_FLAG)
	@echo "$(Y)	Created [objs_flag]"

# ------------------------------------------------------------------- CLEANING
clean:
	@echo "$(NC)Removing [$(NAME)] objs..."
	@rm -rf $(OBJS_DIR)
	@echo "$(NC)Destroying [mylib] archives..."
	@$(MAKE) fclean -C $(MYLIB_DIR)

fclean: clean
	@echo "$(NC)Removing [$(NAME)]..."
	@rm -f $(NAME)
	@echo "$(G)	[$(NAME)] removed!"

re: fclean all

# -------------------------------------------------------- MLX42 & DEPENDENCIES
$(MLX42): $(MLX42_DIR)
	@echo "$(NC)Compiling [$@]..."
	cd $(MLX42_DIR) && cmake -B build
	$(MAKE) -C $(MLX42_DIR)build -j4

$(MLX42_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR)
	cd $(MLX42_DIR) && rm -rf .git

clean_mlx:
	@echo "$(NC)Removing [MLX42 build]..."
	@rm -rf $(MLX42_DIR)/build/
	@echo "$(G)	[MLX42 build] removed!"

fclean_mlx:
	@echo "$(NC)Removing [MLX42]..."
	@rm -rf $(MLX42_DIR)
	@echo "$(G)	[MLX42] removed!"

# ------------------------------------------------------------------- MAP TESTS
test: $(NAME)
	@for map in $(shell ls ./maps/invalid/); do \
		echo "$(Y)Test [$$map]$(NC)"; \
		cat ./maps/invalid/$$map; \
		echo "$(G)Result:$(NC)"; \
		./$(NAME) ./maps/invalid/$$map; \
		echo "___________________________________\n"; \
	done

test_bonus: $(NAME)
	@for map_bonus in $(shell ls ./maps/bonus_invalid/); do \
		echo "$(Y)Test [$$map_bonus]$(NC)"; \
		cat ./maps/bonus_invalid/$$map_bonus; \
		echo "$(G)Result:$(NC)"; \
		./$(NAME) ./maps/bonus_invalid/$$map_bonus; \
		echo "___________________________________\n"; \
	done

# ---------------------------------------------------------------- LEAKS FINDER
leaks: $(LEAK_FINDER)

$(LEAK_FINDER):
	@echo "$(NC)Getting leak_checker...(visit $(G)$(GET_LEAK_FINDER) $(NC)and leave a star!)"
	@$(GET_LEAK_FINDER)
	@$(MAKE) -C ./leak_finder
	@cp ./leak_finder/libft_malloc.so ./
	@cp ./leak_finder/libft_malloc_x86_64_Darwin.so ./
	@echo "$(G)	[leak_finder] compiled!"
	@echo "$(Y)	Make sure to add necessary flag during compile..."

clean_leaks:
	@echo "$(NC)Removing [leak_finder]..."
	@rm -rf libft_malloc_x86_64_Darwin.so
	@rm -rf libft_malloc.so
	@rm -rf ./leak_finder
	@echo "$(G)	[leak_finder] removed!"

G = \033[0;32m
Y = \033[0;33m
R = \033[0;31m
NC = \033[0m

.PHONY: all clean fclean fclean_mlx re bonus leaks test

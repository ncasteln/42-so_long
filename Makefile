# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 15:21:33 by ncasteln          #+#    #+#              #
#    Updated: 2023/07/19 07:56:43 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -g -Wall -Wextra #################################################################(-Werror)

# ------------------------------------------------------------------------ MYLIB
MYLIB = $(LIBFT) $(FT_PRINTF) $(GNL) $(LIBNC)
MYLIB_DIR = ./lib/mylib/
LIBFT = $(MYLIB_DIR)libft/libft.a
FT_PRINTF = $(MYLIB_DIR)ft_printf/libftprintf.a
GNL = $(MYLIB_DIR)get_next_line/libgnl.a
LIBNC = $(MYLIB_DIR)libnc/libnc.a

# ------------------------------------------------------------------------ MLX42
MLX42 = $(MLX42_DIR)build/libmlx42.a
MLX42_DIR = ./lib/MLX42/

# ------------------------------------------------------------------------- GLFW
# GLFW = -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
GLFW = -lglfw -L"/goinfre/ncasteln/.brew/Cellar/glfw/3.3.8/lib"

# ------------------------------------------------------------------------- SRCS
VPATH = ./src/:./src_bonus/
OBJS_DIR = ./objs/
# ------------------------------------------------------------------------- MAND
SRC = main.c \
	window_settings.c \
	state_print.c \
	lst_to_dptr.c \
	key_handling.c \
	arg_validation.c \
	map_validation.c \
	move_calc.c \
	path_validation.c \
	map_drawing.c \
	free_all.c \
	display_messages.c
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
OBJS_FLAG = $(OBJS_DIR).mand_flag

# ------------------------------------------------------------------------ BONUS
SRC_BONUS = main_bonus.c \
	window_settings_bonus.c \
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
# OBJS_BONUS = $(addprefix $(OBJS_DIR), $(SRC_BONUS:.c=.o))
ifneq (,$(filter bonus,$(MAKECMDGOALS)))
	OBJS_FLAG = $(OBJS_DIR).bonus_flag
	OBJS = $(addprefix $(OBJS_DIR), $(SRC_BONUS:.c=.o))
# SRCS += $(SRC_BONUS)
endif

# --------------------------------------------------------------------- INCLUDES
INCLUDE = -I ./include/ \
	-I ./lib/mylib/libft/include/ \
	-I ./lib/mylib/ft_printf/include/ \
	-I ./lib/mylib/get_next_line/ \
	-I ./lib/mylib/libnc/include/ \
	-I ./lib/MLX42/include/MLX42/

# ------------------------------------------------------------------------ RULES
all: $(NAME)

bonus: $(NAME)

$(NAME): $(MYLIB) $(MLX42) $(OBJS)
	@echo "$(NC)Compiling $@ executable file..."
	@$(CC) $(CFLAGS) \
	$(OBJS) $(MYLIB) $(MLX42) \
	$(GLFW) \
	-o $(NAME)
	@echo "$(GREEN)	$@ successfully compiled!"

# $(NAME): $(MYLIB) $(MLX42) $(OBJS_BONUS)
# 	@echo "$(NC)Compiling $@ executable file..."
# 	@$(CC) $(CFLAGS) \
# 	$(OBJS_BONUS) $(MYLIB) $(MLX42) \
# 	$(GLFW) \
# 	-o $(NAME)
# 	@echo "$(GREEN)	$@ successfully compiled!"

$(MYLIB):
	@echo "$(NC)Compiling dependencies..."
	@$(MAKE) -C $(MYLIB_DIR)

$(MLX42):
	@echo "$(NC)Compiling $@..."
	cd $(MLX42_DIR) && cmake -B build
	$(MAKE) -C $(MLX42_DIR)build -j4

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@cc $(CFLAGS) -c $< -o $@ $(INCLUDE)

# $(OBJS_FLAG):
# 	@rm -rf $(OBJS_DIR).mand_flag
# 	@rm -rf $(OBJS_DIR).bonus_flag
# 	@mkdir -p $(OBJS_DIR)
# 	@touch $(OBJS_FLAG)
# 	@echo "$(YELLOW)	Created [objs_flag] to not relink..."

clean:
	@echo "$(NC)Removing objs..."
	@rm -rf $(OBJS_DIR)
	@$(MAKE) clean -C $(MYLIB_DIR)

fclean: clean
	@echo "$(NC)Destroying library dependencies..."
	@rm -f $(NAME) $(NAME)_bonus
	@$(MAKE) fclean -C $(MYLIB_DIR)

re: fclean all

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

.PHONY: all, clean, fclean, re

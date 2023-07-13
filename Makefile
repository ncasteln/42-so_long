# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 15:21:33 by ncasteln          #+#    #+#              #
#    Updated: 2023/07/13 16:18:34 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -g -Wall -Wextra #################################################################(-Werror)

# ------------------------------------ MYLIB ------------------------------------
MYLIB = $(LIBFT) $(FT_PRINTF) $(GNL) $(LIBNC)
MYLIB_DIR = ./lib/mylib/
LIBFT = $(MYLIB_DIR)libft/libft.a
FT_PRINTF = $(MYLIB_DIR)ft_printf/libftprintf.a
GNL = $(MYLIB_DIR)get_next_line/libgnl.a
LIBNC = $(MYLIB_DIR)libnc/libnc.a

# ------------------------------------ MLX42 ------------------------------------
MLX42 = $(MLX42_DIR)build/libmlx42.a
MLX42_DIR = ./lib/MLX42/

# ------------------------------------ GLFW ------------------------------------
# GLFW = -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
GLFW = -lglfw -L"/goinfre/ncasteln/.brew/Cellar/glfw/3.3.8/lib"

# ------------------------------------ SRCS ------------------------------------
SRC = main.c \
	window_settings.c \
	state_print.c \
	lst_to_dptr.c \
	enemies_handling.c \
	key_handling.c \
	event_handling.c \
	arg_validation.c \
	map_validation.c \
	move_handling.c \
	path_validation.c \
	map_building.c \
	free_all.c \
	sl_error.c
VPATH = ./src/
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
OBJS_DIR = ./objs/

# ------------------------------------ INCLUDES --------------------------------
INCLUDE = -I ./include/ \
	-I ./lib/mylib/libft/include/ \
	-I ./lib/mylib/ft_printf/include/ \
	-I ./lib/mylib/get_next_line/ \
	-I ./lib/mylib/libnc/include/ \
	-I ./lib/MLX42/include/MLX42/

# ------------------------------------ RULES -----------------------------------
all: $(NAME)

$(NAME): $(MYLIB) $(MLX42) $(OBJS)
	@echo "$(NC)Compiling $@ executable file..."
	@$(CC) $(CFLAGS) \
	$(OBJS) $(MYLIB) $(MLX42) \
	$(GLFW) \
	-o $@
	@echo "$(GREEN)	$@ successfully compiled!"

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

clean:
	@echo "$(NC)Removing objs..."
	@rm -rf $(OBJS_DIR)
	@$(MAKE) clean -C $(MYLIB_DIR)

fclean: clean
	@echo "$(NC)Destroying library dependencies..."
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(MYLIB_DIR)

re: fclean all

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

.PHONY: all, clean, fclean, re

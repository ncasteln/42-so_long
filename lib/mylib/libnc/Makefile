# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 11:38:13 by ncasteln          #+#    #+#              #
#    Updated: 2023/07/10 11:00:47 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libnc.a
CFLAGS = -Wall -Wextra -Werror

SRC = nc_is_valid_ext.c \
	nc_exit.c \
	nc_dptr_size.c \
	nc_dptr_deepcpy.c \
	nc_dptr_free.c \
	nc_dptr_print.c
VPATH = ./src/
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
OBJS_DIR = ./objs/
BONUS_OBJS = $(addprefix $(OBJS_DIR), $(BONUS_SRC:.c=.o))

LIBFT = libft.a
LIBFT_DIR = ../libft/
FT_PRINTF = libftprintf.a
FT_PRINTF_DIR = ../ft_printf/
GNL = libgnl.a
GNL_DIR = ../get_next_line/

INCLUDE = -I ./include/ \
	-I ../libft/include/ \
	-I ../ft_printf/include/ \
	-I ../get_next_line/

all: $(NAME)

$(NAME): $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS) \
	$(LIBFT_DIR)$(LIBFT) \
	$(FT_PRINTF_DIR)$(FT_PRINTF) \
	$(GNL_DIR)$(GNL)
	@echo "$(GREEN)	$(NAME) successfully created!"

#$(LIBFT) $(FT_PRINTF) $(GNL) // add this to $(NAME) rule or not?

# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR)

# $(FT_PRINTF):
# 	$(MAKE) -C $(FT_PRINTF_DIR)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)	$(NAME) objs successfully removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)	$(NAME) successfully removed!"

re: fclean all

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

.PHONY: all, clean, fclean, re, bonus

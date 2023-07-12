# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 09:08:19 by ncasteln          #+#    #+#              #
#    Updated: 2023/07/05 09:28:36 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c \
	get_next_line_utils.c
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
OBJS_DIR = ./objs/

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)	$(NAME) successfully created!"

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

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

.PHONY: all, clean, fclean, re

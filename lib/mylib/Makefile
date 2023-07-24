# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 09:27:12 by ncasteln          #+#    #+#              #
#    Updated: 2023/07/24 08:53:46 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mylib

FT_PRINTF_DIR = ./ft_printf/
LIBFT_DIR = ./libft/
GNL_DIR = ./get_next_line/

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR)
	@$(MAKE) -C $(GNL_DIR)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(FT_PRINTF_DIR)
	@$(MAKE) clean -C $(GNL_DIR)

fclean:
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(FT_PRINTF_DIR)
	@$(MAKE) fclean -C $(GNL_DIR)

re: fclean all

.PHONY: all, clean, fclean, re

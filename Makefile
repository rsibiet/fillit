# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/12 12:48:58 by ddesnoye          #+#    #+#              #
#    Updated: 2015/12/28 20:02:02 by rsibiet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit

FTC = main.c \
      checkblocks.c \
      final_check.c \
	  end_of_check.c \
      resolve_me.c \
      path_finder.c \
      path_finderb.c \
      place_blocs.c \
      place_blocsb.c \
      path_bis.c \
	  place_blocsv0.c \
	  place_blocsv1.c \
	  resolve_again.c \
	  finish_him.c

FTO = $(subst .c,.o,$(FTC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@echo ""
	@make -C ./libft
	@gcc -o $(NAME) $(FTO) ./libft/libft.a
	@echo "\033[32m$(NAME) created!\033[0m"

%.o: %.c
	@gcc -Wall -Wextra -Werror -I./libft -c $<
	@echo "\033[33m.\033[0m\c"

clean:
	@make -C ./libft clean
	@rm -rf $(FTO)
	@echo "\033[33m$(NAME) object deleted!\033[0m"

fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME)
	@echo "\033[31m$(NAME) deleted!\033[0m"

re: fclean all



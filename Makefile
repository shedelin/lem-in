# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shedelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/18 20:30:31 by shedelin          #+#    #+#              #
#    Updated: 2014/02/18 20:30:44 by shedelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=lem-in
CC=gcc
FLAGS=-Wall -Wextra -Werror
LIB=libft/
HEADER=includes/
SRC = lm_main.c \
	  lm_nest.c \
	  lm_ants.c \
	  lm_room.c \
	  lm_pipe.c \
	  lm_move.c \
	  lm_print.c \
	  lm_check.c \
	  lm_error.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIB)
	@$(CC) $(FLAGS) -o $(NAME) $^ -I. -I$(LIB)$(HEADER) -L$(LIB) -lft
	@echo "\033[1;32mlem-in OK\033[0m"

%.o: %.c
	@echo -n .
	@$(CC) $(FLAGS) -o $@ -c $< -I. -I$(LIB)$(HEADER)

clean:
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB) $@
	@rm -f $(NAME)

re: fclean all

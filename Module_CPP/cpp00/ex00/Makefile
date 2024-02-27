# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 17:54:54 by memahote          #+#    #+#              #
#    Updated: 2023/11/20 17:54:54 by memahote         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

OBJ_DIR = obj/

SRC = megaphone.cpp

OBJ      = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

CC				= c++
RM				= rm -rf
FLAGS			= -Wall -Wextra -Werror -std=c++98
DEP_FLAGS		= -MMD -MP
MKDIR           = mkdir -p
MAKE            = make -C

.PHONY: all clean fclean re

$(NAME): $(OBJ) 
	${CC} $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o: %.c 
	$(MKDIR) $(@D)
	$(CC) $(FLAGS) $(DEP_FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
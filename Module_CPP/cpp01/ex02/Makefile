# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 21:36:59 by memahote          #+#    #+#              #
#    Updated: 2024/02/27 21:36:59 by memahote         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME = Brain

SRC_DIR 	= srcs/
OBJ_DIR		= obj/

SRC = 	main.cpp 

SRC_PATH 	= $(addprefix $(SRC_DIR), $(SRC))
OBJ      	= $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRC_PATH))

CC				= c++
RM				= rm -rf
FLAGS			= -Wall -Wextra -Werror -std=c++98
MKDIR           = mkdir -p
MAKE            = make -C



.PHONY: all clean fclean re 

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) 


$(OBJ_DIR)%.o: %.cpp
	$(MKDIR) $(@D)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
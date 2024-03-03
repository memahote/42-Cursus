# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 22:36:14 by memahote          #+#    #+#              #
#    Updated: 2024/02/28 22:36:14 by memahote         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME = replace

SRC_DIR 	= srcs/
INC_DIR 	= include/
OBJ_DIR		= obj/

SRC = 	main.cpp replace.cpp

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
	$(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 12:24:36 by memahote          #+#    #+#              #
#    Updated: 2024/02/27 12:24:36 by memahote         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

INC_DIR 	= include/
SRC_DIR 	= srcs/
OBJ_DIR		= 	obj/

SRC = 	main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

SRC_PATH 	= $(addprefix $(SRC_DIR), $(SRC))
OBJ      	= $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRC_PATH))
INC			= $(addprefix $(INC_DIR), Zombie.hpp)
DEP			= $(patsubst %.cpp, $(OBJ_DIR)%.d, $(SRC_PATH))

CC				= c++
RM				= rm -rf
FLAGS			= -Wall -Wextra -Werror -std=c++98
DEP_FLAGS		= -MMD -MP
MKDIR           = mkdir -p
MAKE            = make -C



.PHONY: all clean fclean re 

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) 

-include $(DEP)

$(OBJ_DIR)%.o: %.cpp
	$(MKDIR) $(@D)
	$(CC) $(FLAGS) $(DEP_FLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
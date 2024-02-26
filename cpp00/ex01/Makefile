NAME = phonebook

INC_DIR 	= includes/
SRC_DIR 	= srcs/
OBJ_DIR		= 	obj/

SRC = 	Contact.cpp \
		PhoneBook.cpp \
		main.cpp

SRC_PATH 	= $(addprefix $(SRC_DIR), $(SRC))
OBJ      	= $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRC_PATH))
INC			= $(addprefix $(INC_DIR), PhoneBook.hpp)
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
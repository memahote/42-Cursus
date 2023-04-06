NAME		=	pipex

INC_DIR		= 	include/
INC			= 	$(INC_DIR)pipex.h

LIB_DIR		= libft/
LIB_A		= $(LIB_DIR)libft.a
LIB_H		= $(LIB_DIR)libft.h

LIST_SRC	= 	do_cmd.c free_tab.c get_path_from_envp.c \
				get_path.c pipex.c process.c 
SRC_DIR		=	source/
SRC			= $(addprefix $(SRC_DIR), $(LIST_SRC))

OBJ_DIR		= obj/
OBJ			= $(LIST_SRC:%.c=$(OBJ_DIR)%.o)

# ----- Compiler -----

CC				= cc
RM				= rm -rf
FLAG			= -Wall -Wextra -Werror -g3
FLAG_LIB		= -I ./libft -L ./libft/libft.a

all:	$(NAME)

lib:
		@make -C $(LIB_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC) $(LIB_H)
				@mkdir -p $(@D) 
				${CC} ${FLAG} -I $(INC_DIR) -I ./libft -c $< -o $@ 

$(NAME):	lib $(OBJ) $(INC)
			${CC} -o $(NAME) $(OBJ) $(FLAG_LIB) $(LIB_A)

clean:		
			@make clean -C $(LIB_DIR)
			${RM} $(OBJ_DIR)

fclean:		clean
			@make fclean -C $(LIB_DIR)
			${RM} ${NAME}

re:			fclean all

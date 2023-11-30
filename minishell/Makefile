################################## VARIABLES ###################################

NAME			= minishell

# ----- FOLDERS ----- #

INC_DIR		= 	include/
LIB_DIR		= 	libft/
SRC_DIR		=	srcs/
OBJ_DIR		= 	obj/


# ----- FILES ----- #

LIST_SRC	= 	main.c


# ----- SHORTCUTS ----- #

INC			= $(addprefix $(INC_DIR), pipex.h)
LIBFT       = $(addprefix $(LIB_DIR), libft.a)
SRC			= $(addprefix $(SRC_DIR), $(LIST_SRC))
OBJ         = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
DEP			= $(patsubst %.c, $(OBJ_DIR)%.d, $(SRC))

# ----- Compiler -----

CC				= cc
RM				= rm -rf
FLAG			= -Wall -Wextra -Werror -g3 
DEP_FLAGS		= -MMD -MP
MKDIR           = mkdir -p
MAKE            = make -C

################################## RULES ###################################

all:	$(NAME)

# bonus: $(NAME_BONUS)

$(NAME):	$(LIBFT) $(OBJ)
			$(CC) $(FLAG) -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft -lreadline


$(LIBFT):	FORCE
		$(MAKE) $(LIB_DIR)

-include $(DEP)

$(OBJ_DIR)%.o: %.c 
	$(MKDIR) $(@D)
	$(CC) $(FLAG) $(DEP_FLAGS) -I $(INC_DIR) -c $< -o $@

clean:		
			$(MAKE) $(LIB_DIR) clean
			${RM} $(OBJ_DIR)

fclean:		clean
			$(MAKE) $(LIB_DIR) fclean
			${RM} ${NAME}
			${RM} ${NAME_BONUS}

re:			fclean all

FORCE:

.PHONY:         all bonus clean fclean FORCE re 

################################## VARIABLES ###################################

NAME			= minishell

# ----- FOLDERS ----- #

INC_DIR		= 	includes/
LIB_DIR		= 	libft/
SRC_DIR		=	srcs/
OBJ_DIR		= 	obj/


# ----- FILES ----- #

LIST_SRC	= 	main.c lexer.c lexer_utils.c list_minishell.c check_syntax.c\
				check_quote_input.c


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

leaks: 		all
			touch valgrind.txt
			rm valgrind.txt
			echo "{" > valgrind_ignore_leaks.txt
			echo "leak readline" >> valgrind_ignore_leaks.txt
			echo "Memcheck:Leak" >> valgrind_ignore_leaks.txt
			echo "..." >> valgrind_ignore_leaks.txt
			echo "fun:readline" >> valgrind_ignore_leaks.txt
			echo "}" >> valgrind_ignore_leaks.txt
			echo "{" >> valgrind_ignore_leaks.txt
			echo "leak add_history" >> valgrind_ignore_leaks.txt
			echo "Memcheck:Leak" >> valgrind_ignore_leaks.txt
			echo "..." >> valgrind_ignore_leaks.txt
			echo "fun:add_history" >> valgrind_ignore_leaks.txt
			echo "}" >> valgrind_ignore_leaks.txt
			valgrind --suppressions=valgrind_ignore_leaks.txt --leak-check=full \
					--show-leak-kinds=all --track-fds=yes \
					--show-mismatched-frees=yes --read-var-info=yes \
					--log-file=valgrind.txt -s ./${NAME}

.PHONY:         all bonus clean fclean FORCE re 

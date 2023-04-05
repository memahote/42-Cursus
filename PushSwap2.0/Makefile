# Folders and Names
NAME			= push_swap
CHECKER_NAME	= checker

INC_DIR			= include/
INC_Name		= pushswap.h
INC				= $(addprefix $(INC_DIR), $(INC_Name))

INSTR			= pa.c pb.c \
				rra.c rrb.c rrr.c \
				ra.c rb.c rr.c \
				sa.c sb.c ss.c
INSTR_DIR		= instruction/
INSTRUCTIONS	= $(addprefix $(INSTR_DIR), $(INSTR))

PARSE			=  number_of_chunk.c sort_array.c is_int.c initialize_struct.c \
				fill_st_a.c array_of_stack.c check_duplicate.c
PARSE_DIR		= parse/
PARSING			= $(addprefix $(PARSE_DIR), $(PARSE))

SORT			= sort_three.c is_sorted.c sort_small.c is_empty.c \
				find_index_smallest.c find_smallest.c find_biggest.c \
				sort_a_to_b.c sort_b_to_a.c update_value.c 
SORT_DIR		= sort/
SORTING			= $(addprefix $(SORT_DIR), $(SORT))

CLEAN			= ft_free.c ft_print_error.c 
CLEAN_DIR		= clean/
CLEANING		= $(addprefix $(CLEAN_DIR), $(CLEAN))

LIST_SRC		=  pushswap.c \
				$(INSTRUCTIONS) $(PARSING) $(SORTING) $(CLEANING)

LIST_SRC_B		= checker.c \
				$(INSTRUCTIONS) $(PARSING) $(SORTING) $(CLEANING)

SRC_DIR			= source/
SRC				= $(addprefix $(SRC_DIR, $(LIST_SRC)))

LIBX_DIR		= libft/
LIBX			= libft.a

OBJ_DIR			= obj/
LIST_OBJ		= $(LIST_SRC:.c=.o)
OBJ				=	$(addprefix $(OBJ_DIR), $(LIST_OBJ))

LIST_OBJ_B		= $(LIST_SRC_B:.c=.o)
OBJ_BONUS		= $(addprefix $(OBJ_DIR), $(LIST_OBJ_B))

# ----- CCompiler -----

CC				= cc
RM				= rm -rf
FLAG			= -Wall -Wextra -Werror -g3
FLAG_LIB		= -I ./libft -L ./libft/libft.a

ascii			=	██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗  \n\
					██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗ \n\
					██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝ \n\
					██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝  \n\
					██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║      \n\
					╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     

all:	lib $(NAME)
		@echo "\033[31mCompiling \033[1mis done !\033[0;31m $(NONE)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
				@mkdir -p $(@D) 
				${CC} ${FLAG} -I $(INC_DIR) -I ./libft -c $< -o $@ 

$(NAME):		$(LIBX_DIR)$(LIBX) $(OBJ) $(INC)
				@echo " $(ascii)"
				@echo "\033[31mCompiling \033[1mobjects files\033[0;31m...\033[0m $(NONE)"
				${CC} -o $(NAME) $(OBJ) $(LIBX_DIR)$(LIBX) $(FLAG_LIB) -s

lib:
				@make -C $(LIBX_DIR) -s

bonus:			$(LIBX_DIR)$(LIBX) $(OBJ_BONUS) $(INC)
				@echo "\033[31mCompiling \033[1mChecker\033[0;31m...\033[0m $(NONE)"
				${CC} -o $(CHECKER_NAME) $(OBJ_BONUS) $(LIBX_DIR)$(LIBX) $(FLAG_LIB) -s

clean:
				@echo "\033[31mRemoving \033[1mobjects files\033[0;31m...\033[0m $(NONE)"
				@make clean -C $(LIBX_DIR) -s
				${RM} $(OBJ_DIR)

fclean:			clean
				@echo "\033[31mAnd \033[1mexecutable file !\033[0;31m\033[0m $(NONE)"
				@make fclean -C $(LIBX_DIR) -s
				$(RM) $(NAME) $(CHECKER_NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus lib

.SILENT:		$(OBJ_DIR) lib $(NAME) $(LIST_OBJ) $(LIST_OBJ_B) bonus all clean fclean

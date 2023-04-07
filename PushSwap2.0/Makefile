################################## VARIABLES ###################################

NAME			= push_swap
CHECKER     	= checker


# ----- FOLDERS ----- #

INC_DIR			= include/
INSTR_DIR		= instruction/
PARSE_DIR		= parse/
SORT_DIR		= sort/
CLEAN_DIR		= clean/
SRC_DIR			= source/
LIB_DIR			= libft/
OBJ_DIR			= obj/

# ----- FILES ----- #

INSTR			= pa.c pb.c \
			  rra.c rrb.c rrr.c \
			  ra.c rb.c rr.c \
			  sa.c sb.c ss.c

PARSE			= number_of_chunk.c sort_array.c is_int.c initialize_struct.c \
			  fill_st_a.c array_of_stack.c check_duplicate.c

SORT			= sort_three.c is_sorted.c sort_small.c is_empty.c \
			  find_index_smallest.c find_smallest.c find_biggest.c \
			  sort_a_to_b.c sort_b_to_a.c update_value.c 

CLEAN			= ft_free.c ft_print_error.c 

INSTRUCTIONS	= $(addprefix $(INSTR_DIR), $(INSTR))
PARSING			= $(addprefix $(PARSE_DIR), $(PARSE))
SORTING			= $(addprefix $(SORT_DIR), $(SORT))
CLEANING		= $(addprefix $(CLEAN_DIR), $(CLEAN))

LIST_SRC		=  pushswap.c \
			   $(INSTRUCTIONS) $(PARSING) $(SORTING) $(CLEANING)

LIST_SRC_B		= checker.c ./sort/is_sorted.c \
			  $(INSTRUCTIONS) $(PARSING) $(CLEANING)

# ----- SHORTCUTS ----- #

SRC             = $(addprefix $(SRC_DIR), $(LIST_SRC))
SRC_B           = $(addprefix $(SRC_DIR), $(LIST_SRC_B))
LIBFT           = $(addprefix $(LIB_DIR), libft.a)
OBJ             = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
OBJ_B           = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_B))
DEP				= $(patsubst %.c, $(OBJ_DIR)%.d, $(SRC))

# ----- COMPILATIONS ----- #

CC				= cc
RM				= rm -rf
FLAG			= -Wall -Wextra -Werror -g3
DEP_FLAGS		= -MMD -MP
MKDIR           = mkdir -p
MAKE            = make -C

################################## RULES ###################################

all:            $(NAME)
	@echo "\033[31mCompiling \033[1mis done !\033[0;31m $(NONE)"

bonus:          $(CHECKER)

$(NAME): $(LIBFT) $(OBJ)
	@echo " $(ascii)"
	@echo "\033[31mCompiling \033[1mobjects files\033[0;31m...\033[0m $(NONE)"
	$(CC) $(FLAG) -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft

$(CHECKER):     $(LIBFT) $(OBJ_B)
	@echo "\033[31mCompiling \033[1mChecker\033[0;31m...\033[0m $(NONE)"
	$(CC) $(FLAG) -o $(CHECKER) $(OBJ_B) -L $(LIB_DIR) -lft

$(LIBFT):   FORCE
	$(MAKE) $(LIB_DIR)

-include $(DEP)

$(OBJ_DIR)%.o: %.c 
	$(MKDIR) $(@D)
	$(CC) $(FLAG) $(DEP_FLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@echo "\033[31mRemoving \033[1mobjects files\033[0;31m...\033[0m $(NONE)"
	$(MAKE) $(LIB_DIR) clean
	$(RM) $(OBJ_DIR)

fclean:     clean
	@echo "\033[31mAnd \033[1mexecutable file !\033[0;31m\033[0m $(NONE)"
	$(MAKE) $(LIB_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(CHECKER)

FORCE:

re:             fclean all

.PHONY:         all bonus clean fclean FORCE re 

################################## CUSTOM ###################################

ascii			=	██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗  \n\
				██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗ \n\
				██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝ \n\
				██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝  \n\
				██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║      \n\
				╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     

_END		:=	\x1b[0m
_BOLD		:=	\x1b[1m
_UNDER		:=	\x1b[4m
_REV		:=	\x1b[7m
_GREY		:=	\x1b[30m
_RED		:=	\x1b[31m
_GREEN		:=	\x1b[32m
_YELLOW		:=	\x1b[33m
_BLUE		:=	\x1b[34m
_PURPLE		:=	\x1b[35m
_CYAN		:=	\x1b[36m
_WHITE		:=	\x1b[37m

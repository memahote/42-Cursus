NAME			= push_swap
CHECKER_NAME	= checker
SRCS			= pushswap.c sort_three.c sort_array.c number_of_chunk.c is_sorted.c \
				is_int.c initialize_struct.c fill_st_a.c array_of_stack.c sort_small.c \
				is_empty.c find_index_smallest.c find_smallest.c  \
				find_biggest.c sort_a_to_b.c  check_duplicate.c\
				sort_b_to_a.c update_value.c ft_print_error.c ft_free.c 

INSTRUCTIONS	= instruction/pa.c instruction/pb.c instruction/rra.c \
				instruction/rrb.c instruction/rrr.c instruction/ra.c instruction/rb.c \
				instruction/rr.c instruction/sa.c instruction/sb.c instruction/ss.c

CHECKER_SRC		= checker.c sort_three.c sort_array.c number_of_chunk.c is_sorted.c \
				is_int.c initialize_struct.c fill_st_a.c array_of_stack.c sort_small.c \
				is_empty.c find_index_smallest.c find_smallest.c  \
				find_biggest.c sort_a_to_b.c  check_duplicate.c\
				sort_b_to_a.c update_value.c ft_print_error.c ft_free.c 

OBJS			= $(SRCS:.c=.o)
CHECKER_OBJ		= $(CHECKER_SRC:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g3

HEADER			= pushswap.h

NONE = \033[39m


ascii			=	██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗  \n\
					██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗ \n\
					██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝ \n\
					██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝  \n\
					██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║      \n\
					╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     
                                                                       

all:			$(NAME) 
				@echo "\033[31mCompiling \033[1mis done !\033[0;31m $(NONE)"

bonus:$(CHECKER_OBJ) $(NAME)
				@echo "\033[31mCompiling \033[1mChecker\033[0;31m...\033[0m $(NONE)"
				@$(MAKE) -C libft/ re -s
				${CC} $(CFLAGS) $(CHECKER_SRC) $(INSTRUCTIONS) -o $(CHECKER_NAME) -L libft/ -lft

$(NAME):		$(OBJS) $(HEADER)
				@echo " $(ascii) $(NONE)"
				@echo "\033[31mCompiling \033[1mobjects files\033[0;31m...\033[0m $(NONE)"
				@$(MAKE) -C libft/ re -s
				${CC} $(CFLAGS) $(SRCS) $(INSTRUCTIONS) -o $(NAME) -L libft/ -lft

clean:
				@echo "\033[31mRemoving \033[1mobjects files\033[0;31m...\033[0m $(NONE)"
				$(RM) $(OBJS) $(CHECKER_OBJ)
				@make -C libft/ clean -s

fclean:			clean
				@echo "\033[31mAnd \033[1mexecutable file !\033[0;31m\033[0m $(NONE)"
				$(RM) $(NAME) $(CHECKER_NAME)
				@make -C libft/ fclean -s

re:				fclean all

.SILENT : clean all fclean $(NAME) re $(SRCS:.c=.o) bonus $(CHECKER_SRC:.c=.o)

.PHONY:			all clean fclean re bonus libft
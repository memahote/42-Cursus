NAME			= push_swap
SRCS			= pushswap.c sort_three.c sort_array.c number_of_chunk.c is_sorted.c \
				is_int.c initialize_struct.c fill_st_a.c array_of_stack.c sort_five.c \
				is_empty.c find_index_smallest.c find_smallest.c check_duplicate.c  \
				find_biggest.c sort_a_to_b.c update_value.c ft_print_error.c\
				sort_b_to_a.c ft_free.c

INSTRUCTIONS	= instruction/pa.c instruction/pb.c instruction/rra.c \
				instruction/rrb.c instruction/rrr.c instruction/ra.c instruction/rb.c \
				instruction/rr.c instruction/sa.c instruction/sb.c instruction/ss.c

SRCS_BONUS			= bonus/get_next_line.c bonus/get_next_line_utils.c

OBJS			= $(SRCS:.c=.o) $(INSTRUCTIONS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -g3

HEADER			= pushswap.h

all:			$(NAME)
				@echo "\033[31mCompiling \033[1mis done !\033[0;31m"
			

$(NAME):		$(OBJS) $(HEADER)
				@echo "\033[31mCompiling \033[1mobjects files\033[0;31m...\033[0m"
				cd libft && make all -s
				${CC} $(CFLAGS) $(SRCS) $(INSTRUCTIONS) -o $(NAME) -L libft/ -lft

clean:
				@echo "\033[31mRemoving \033[1mobjects files\033[0;31m...\033[0m"
				$(RM) $(OBJS) 
				cd libft && make clean -s

fclean:			clean
				@echo "\033[31mAnd \033[1mexecutable file !\033[0;31m\033[0m"
				$(RM) $(NAME) 
				cd libft && make fclean -s

re:				fclean all

.SILENT : clean all fclean $(NAME) re $(SRCS:.c=.o) $(INSTRUCTIONS:.c=.o)

.PHONY:			all clean fclean re bonus libft
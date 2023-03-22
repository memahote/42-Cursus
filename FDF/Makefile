# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 16:23:32 by memahote          #+#    #+#              #
#    Updated: 2023/02/26 16:23:32 by memahote         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

INC			=	fdf.h 
INC_DIR		=	./include/

HEADERS		= $(addprefix $(INC_DIR), $(INC))

SRC			=	fdf.c 			\
				read_file.c		\
				draw.c 			\
				init.c clean.c	\
				deal_key.c
					


LIBFT_DIR	=	libft/
LIBFT_A		=	$(LIBFT_DIR)libft.a

OBJ_DIR		=	build/
OBJ			=	$(SRC:%.c=$(OBJ_DIR)%.o)

CC			=	cc
CC_FLAGS	=	-Wextra -Werror -Wall

MLX_DIR	=	mlx_linux/
MLX_A	=	$(MLX_DIR)libmlx.a
MLX_FLAG = -L $(MLXDIR) -lm -lmlx -lXext -lX11

all: build_libft $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(MLX_A) $(LIBFT_DIR)
		$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT_A) $(MLX_A) $(MLX_FLAG) -o $@
	

build_libft: $(LIBFT_DIR)
		$(MAKE) -C $(LIBFT_DIR)

$(MLX_A): $(MLX_DIR)
		$(MAKE) -C $(MLX_DIR)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
		mkdir -p $(@D)
		$(CC) $(CC_FLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX_DIR) -c $< -o $@

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		$(MAKE) clean -C $(MLX_DIR)
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -rf $(NAME)
		$(MAKE) fclean -s -C $(LIBFT_DIR)
		

re: fclean all

.SILENT :

.PHONY: all clean fclean re build_libft
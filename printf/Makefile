# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 13:43:05 by memahote          #+#    #+#              #
#    Updated: 2022/12/22 16:39:01 by memahote         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_printf.c ft_put_c.c ft_put_x.c ft_put_p.c ft_putd_i.c \
					ft_put_s.c ft_put_u.c ft_base.c

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
HEADER			= ft_printf.h
NAME			= libftprintf.a

all:			$(NAME)

%.o: %.c		$(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS) $(HEADER)
				ar rc $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
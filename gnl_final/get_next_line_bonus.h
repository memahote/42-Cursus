/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:19:38 by memahote          #+#    #+#             */
/*   Updated: 2022/11/27 14:39:35 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char		*get_next_line(int fd);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_extract(char *str);
char		*ft_reset(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
int			ft_strlen(char *s);
int			ft_strchr(char *s, char c);

#endif

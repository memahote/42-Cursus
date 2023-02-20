/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:35:31 by memahote          #+#    #+#             */
/*   Updated: 2022/12/06 13:50:40 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

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

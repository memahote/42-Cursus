/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:19:30 by memahote          #+#    #+#             */
/*   Updated: 2022/12/19 14:27:05 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd, char *line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(buffer), NULL);
		buffer[i] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*line[OPEN_MAX];
	char			*linefinal;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1 || fd > OPEN_MAX)
		return (free(line[fd]), line[fd] = NULL, NULL);
	line[fd] = ft_read(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	linefinal = ft_extract(line[fd]);
	if (!linefinal)
		return (free(line[fd]), line[fd] = NULL, NULL);
	line[fd] = ft_reset(line[fd]);
	return (linefinal);
}

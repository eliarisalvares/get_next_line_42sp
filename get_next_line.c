/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:39:55 by elraira-          #+#    #+#             */
/*   Updated: 2021/09/03 16:13:17 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

static char	*ft_end_of_file(int bytes_read, char *line)
{
	if (!bytes_read && line[bytes_read] == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}

static char	*ft_read_line(int fd, char *line, char **buff)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		aux = line;
		line = ft_strjoin(line, buffer);
		free(aux);
		if (ft_strchr(line, '\n'))
		{
			aux = *buff
			*buff = ft_strdup(ft_strchr(line, '\n') + 1);
			free(aux);
			line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(*buff));
			break ;
		}
	}
	return (ft_end_of_file(bytes_read, line));
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	if (!buff)
		buff = ft_strdup("");
	line = ft_strdup(buff);
	free(buff);
	buff = NULL;
	line = ft_read_line(fd, line, &buff);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamamototaimu <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:24:50 by yamamototaimu     #+#    #+#             */
/*   Updated: 2025/02/01 16:48:12 by yamamototaimu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <stdio.h> // デバック用です

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if ((!dest && !src) && n > 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s)
	{
		i = n;
		while (i--)
			d[i] = s[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

char	*return_line(char *newline_pos, char *line, char *buffer)
{
	*newline_pos = '\0';
	line = ft_strjoin(line, buffer);
	ft_memmove(buffer, newline_pos + 1, ft_strlen(newline_pos + 1) + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*newline_pos;
	int			read_bytes;

	line = NULL;
	if (fd <= -1 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (!(*buffer))
		{
			read_bytes = read(fd, buffer, BUFFER_SIZE);
			if (read_bytes <= 0)
				return (line);
			buffer[read_bytes] = '\0';
		}
		newline_pos = find_newline(buffer);
		if (newline_pos)
			return (return_line(newline_pos, line, buffer));
		else
		{
			line = ft_strjoin(line, buffer);
			*buffer = '\0';
		}
	}
}

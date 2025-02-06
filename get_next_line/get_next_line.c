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

char	*get_next_line(int fd)
{
	void	*line;
	int		read_byte;

	line = malloc(BUFFER_SIZE);
	read_byte = read(fd, line, BUFFER_SIZE);
	if ((read_byte == BUFFER_SIZE) && ((char *)line)[BUFFER_SIZE] != '\0')
		return (-1);


	free(line);
	return (line);
}

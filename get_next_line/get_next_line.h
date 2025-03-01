/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:38:16 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/07 13:38:18 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>

int		ft_strlen(char *str);
void	ft_strcpy(char *new_line, char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*find_newline(char *buffer);
char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
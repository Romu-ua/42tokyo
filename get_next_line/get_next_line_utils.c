/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:38:37 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/07 13:38:39 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_strcpy(char *new_line, char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		*new_line = *str;
		new_line++;
		str++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	char	*new_line;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	new_line = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	ft_memset(new_line, 0, lens1 + lens2 + 1);
	if (!new_line)
		return (NULL);
	if (s1)
		ft_strcpy(new_line, s1);
	if (s2)
		ft_strcpy(new_line + lens1, s2);
	free(s1);
	return (new_line);
}

char	*find_newline(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (buffer);
		buffer++;
	}
	return (NULL);
}

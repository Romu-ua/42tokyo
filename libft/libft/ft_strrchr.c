/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:31:26 by hyamamot          #+#    #+#             */
/*   Updated: 2024/10/29 14:31:28 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

char *ft_strrchr(const char *s, int c)
{
	int i;

	i = strlen(s);
	while (i)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
		
}
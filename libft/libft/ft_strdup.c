/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:38:49 by hyamamot          #+#    #+#             */
/*   Updated: 2024/10/29 16:38:50 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s, size_t n)
{
	size_t	i;
	char	*dest;

	dest = (char *)malloc(n * sizeof(char));
	i = 0;
	while (i < n)
	{
		if (s[i] == '\0')
			break;
		dest[i] = s[i];
		i++;
	}
	if (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

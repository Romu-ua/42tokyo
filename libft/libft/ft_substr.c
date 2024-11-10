/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:48:27 by hyamamot          #+#    #+#             */
/*   Updated: 2024/10/29 16:48:28 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*malloc_1(void)
{
	char	*subs;

	subs = (char *)malloc(1);
	if (!subs)
		return (NULL);
	subs[0] = '\0';
	return (subs);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	const size_t	s_len = ft_strlen(s);
	char			*subs;

	if (!s)
		return (NULL);
	if (start >= s_len)
	{
		subs = malloc_1();
		if (!subs)
			return (NULL);
	}
	if (len > s_len - start)
		len = s_len - start;
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

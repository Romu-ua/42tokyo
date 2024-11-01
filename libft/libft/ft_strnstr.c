/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:05:53 by hyamamot          #+#    #+#             */
/*   Updated: 2024/10/29 15:05:55 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;
	size_t little_len;

	if (little[0] == '\0')
		return ((char *)big);

	i = 0;
	little_len = strlen(little);
	while (i < len - little_len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (j < little_len)
			{
				if (big[i + j] != little[j])
					break;
				j++;
			}
			return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

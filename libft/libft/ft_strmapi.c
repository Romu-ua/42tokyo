/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:36:53 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/01 11:36:54 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*convs;
	const int	len = ft_strlen(s);
	int			i;

	if (!s || !f)
		return (NULL);
	convs = (char *)malloc(sizeof(char) * (len + 1));
	if (!convs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		convs[i] = f(i, s[i]);
		i++;
	}
	convs[i] = '\0';
	return (convs);
}

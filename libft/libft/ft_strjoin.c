/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:26:58 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/01 09:27:39 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strjoin(char const *s1, char const *s2)
{
	const int	lens1 = ft_strlen(s1);
	const int	lens2 = ft_strlen(s2);
	int			i;
	char		*result;

	result = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	i = 0;
	while (i < lens1)
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while(i < lens2)
	{
		result[lens1 + i] = s2[i];
		i++;
	}
	result[lens1 + lens2] = '\0';
	return (result);
}
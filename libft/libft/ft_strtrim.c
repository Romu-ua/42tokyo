/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:54:17 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/01 09:54:19 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const int		setlen = ft_strlen(set);
	const int		s1len = ft_strlen(s1);
	char			*result;
	int				is_trim;
	int				i;

	is_trim = 1;
	i = 0;
	while (i < setlen)
	{
		if (s1[i] != set[i])
		{
			is_trim = 0;
			break;
		}
		i++;
	}
	i = 0;
	while (i < setlen)
	{
		if (s1[s1len - setlen + i] != set[i])
		{
			is_trim = 0;
			break;
		}
		i++;
	}
	if (is_trim)
		result = ft_substr(s1, (unsigned int)setlen, (size_t)(s1len - setlen * 2));
	return (result);
}
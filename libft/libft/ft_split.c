/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:27:11 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/01 10:27:12 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			cnt++;
		s++;
	}
	return (cnt + 1);
}

char	**ft_set(char const *s, char c)
{
	const int	split_count = count(s, c);
	char		**result;

	result = (char **)malloc(sizeof(char) * (split_count + 1));
	return (result);
}

void	ft_strset(char const *s, char **result, int i, int j, int prevlen)
{
	int		k;

	k = 0;
	while (k < i - prevlen)
	{
		result[j][k] = s[i - prevlen + k];
		k++;
	}
	result[j][k] = '\0';
}

void	ft_free(char **result, char const *s, char c)
{
	const int	cnt = count(s, c);
	int			i;

	i = 0;
	while (i < cnt)
	{
		free(result[i]);
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	const int	len = ft_strlen(s);
	char		**result;
	int			prevlen;
	int			i;
	int			j;

	result = ft_set(s, c);
	j = 0;
	i = 0;
	prevlen = 0;
	while (i < len)
	{
		if (s[i] == c)
		{
			result[j] = (char *)malloc(sizeof(char) * (i - prevlen + 1));
			if (!result)
			{
				ft_free(result, s, c);
				return (NULL);
			}
			ft_strset(s, result, i, j, prevlen);
			prevlen = i;
		}
		i++;
	}
	return (result);
}

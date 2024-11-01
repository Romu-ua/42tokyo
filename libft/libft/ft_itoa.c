/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:15:09 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/01 11:15:11 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*is_zero(char *result)
{
	result = (char *)malloc(sizeof(char) * 2);
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

int	count_len(int n)
{
	int	len;

	len = 0;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*is_nmalloc(int is_negative, int len, char *result)
{
	if (is_negative)
		result = (char *)malloc(sizeof(char *) * (len + 2));
	else
		result = (char *)malloc(sizeof(char *) * (len + 1));
	return (NULL);
}

void	is_set(unsigned int n, int len, int is_negative, char *result)
{
	int	i;

	i = 0;
	while (i < len)
	{
		result[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (is_negative)
	{
		result[i] = '-';
		result[i + 1] = '\0';
	}
	else
		result[i] = '\0';
}

char	*ft_itoa(int n)
{
	char			*result;
	int				is_negative;
	const int		len = count_len(n);

	result = NULL;
	if (n == 0)
	{
		result = is_zero(result);
		if (!result)
			return (NULL);
	}
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = (unsigned int)(-(n + 1)) + 1;
	}
	else
		n = (unsigned int)n;
	result = is_nmalloc(is_negative, len, result);
	if (!result)
		return (NULL);
	is_set(n, len, is_negative, result);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:25:55 by hyamamot          #+#    #+#             */
/*   Updated: 2024/10/29 15:25:56 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	check_sign(const char **nptr)
{
	int	is_negative;

	is_negative = 0;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			is_negative = 1;
		(*nptr)++;
	}
	return (is_negative);
}

int	ft_atoi(const char *nptr)
{
	int			is_negative;
	int			result;

	while (ft_isspace(*nptr))
		nptr++;
	is_negative = check_sign(&nptr);
	result = 0;
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
		if (is_negative && - result < INT_MIN)
			return (INT_MIN);
		else if (!is_negative && result > INT_MAX)
			return (INT_MAX);
	}
	if (is_negative)
		return (-result);
	else
		return (result);
}

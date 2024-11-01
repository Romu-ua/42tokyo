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

int	ft_atoi(const char *nptr)
{
	int			is_negative;
	int			i;
	int			result;
	const char	*last_nptr;

	is_negative = 0;
	if (nptr[0] == '-' || nptr[0] == '+')
	{
		if (nptr[0] == '-')
			is_negative = 1;
		nptr++;
	}
	i = 0;
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
		{
			last_nptr = (nptr + i);
			break;
		}
		i++;
	}
	if (!nptr[i])
		last_nptr = nptr + i;
	result = 0;
	while (nptr != last_nptr)
	{
		result = result * 10 + (*nptr - '0'); 
		nptr++;
	}
	return (result);
}

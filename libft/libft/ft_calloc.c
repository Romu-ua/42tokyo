/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:00:39 by hyamamot          #+#    #+#             */
/*   Updated: 2024/10/29 16:00:40 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	int		mul;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	mul = nmemb * size;
	result = malloc(mul);
	ft_memset(result, 0, mul);
	return (result);
}
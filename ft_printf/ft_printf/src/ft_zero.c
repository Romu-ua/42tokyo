/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:46:09 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/15 17:46:10 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_zero(char *output)
{
	output[0] = '0';
	output[1] = 'x';
	output[2] = '0';
	output[3] = '\0';
	return ;
}
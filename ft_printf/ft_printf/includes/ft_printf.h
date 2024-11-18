/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:12:41 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/13 21:12:42 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
#include <limits.h>

# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_c_printf(int c);
int		ft_s_printf(char *str);
int		ft_p_printf(void *pointer);
int		ft_id_printf(int nbr);
int		ft_u_printf(unsigned int nbr);
int		ft_x_printf(unsigned int nbr);
int		ft_xx_printf(unsigned int nbr);
int		ft_per_printf(void);
int		ft_nbrlen_hex(int num);
int		ft_nbrlen_uns(unsigned int n);
int		ft_nbrlen(int n);
void	ft_puthexnbr(unsigned int n);
void	ft_puthexnbr_l(unsigned int n);

#endif

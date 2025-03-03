/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:16:28 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/03 15:16:31 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!argv || !*argv)
		return (0);
	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strcmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strcmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, 1);
		exit(1);
	}
}
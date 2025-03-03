/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:20:09 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/02 18:20:09 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(1);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_0)
		fractal->iteration_definetion += 10;
	else if (keysym == XK_1)
		fractal->iteration_definetion -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x_old;
	double	mouse_y_old;
	double	mouse_x_new;
	double	mouse_y_new;

	mouse_x_old = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	mouse_y_old = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	if (button == Button5)
		fractal->zoom *= 0.95;
	else if (button == Button4)
		fractal->zoom *= 1.05;
	mouse_x_new = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	mouse_y_new = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	fractal->shift_x += mouse_x_old - mouse_x_new;
	fractal->shift_y += mouse_y_old - mouse_y_new;
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, 2, 0, WIDTH) * fractal->zoom + fractal->shift_x);
		fractal->julia_y = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom + fractal->shift_y);
		fractal_render(fractal);
	}
	return (0);
}

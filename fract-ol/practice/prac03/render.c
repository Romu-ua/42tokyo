/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:20:30 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/02 18:20:31 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct	s_tmp
{
	int	x;
	int	y;
}	t_tmp;

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandelbrot_vs_julia_init(t_complex *z, t_complex *c, t_fractal *fractal, t_tmp xy)
{
	if (!ft_strcmp(fractal->name, "julia", 5))
	{
		z->x = (map(xy.x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		z->y = (map(xy.y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		z->x = 0.0;
		z->y = 0.0;
		c->x = (map(xy.x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		c->y = (map(xy.y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	}
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	t_tmp		xy;
	int			i;
	int			color;

	xy.x = x;
	xy.y = y;
	mandelbrot_vs_julia_init(&z, &c, fractal, xy);
	i = 0;
	while (i < fractal->iteration_definetion)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iteration_definetion);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img_ptr,
							0, 0);
	return ;
}

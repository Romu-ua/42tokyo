/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:20:50 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/02 18:20:51 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> // TODO debugging
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

#define ERROR_MESSAGE "Please enter \n\t\" ./fractol mandelbrot\" or \n\t\" ./fractol julia <x> <y>\n"
#define WIDTH	800
#define HEIGHT	800
#define BLACK       0x000000
#define WHITE       0xFFFFFF
#define RED         0xFF0000
#define GREEN       0x00FF00
#define BLUE        0x0000FF
#define MAGENTA_BURST   0xFF00FF
#define LIME_SHOCK      0xCCFF00
#define NEON_ORANGE     0xFF6600
#define PSYCHEDELIC_PURPLE 0x660066
#define AQUA_DREAM      0x33CCCC
#define HOT_PINK        0xFF66B2
#define ELECTRIC_BLUE   0x0066FF
#define LAVA_RED        0xFF3300

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	int		iteration_definetion;
	int		escape_value;
	double	julia_x;
	double	julia_y;
	double	shift_x;
	double	shift_y;
	double	zoom;
}				t_fractal;

int		ft_strcmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);
double	atodbl(char *s);
void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int	key_handler(int keysym, t_fractal *fractal);
int	mouse_handler(int button, int x, int y, t_fractal *fractal);
int	close_handler(t_fractal *fractal);
int	julia_track(int c, int y, t_fractal *fractal);


#endif

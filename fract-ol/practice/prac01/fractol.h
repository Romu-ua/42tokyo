#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> // TODO debugging
# include <stdlib.h> // malloc free
# include <unistd.h> // write
# include <math.h>
# include "mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\" ./fractol mandelbrot\" or \n\t\" ./fractol julia <x> <y>\n"

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
	void	*mlx_connection;
	void	*mlx_windows;
	t_img	img;
	// TODO
}				t_fractal;


int	ft_strcmp(char *s1, char *s2, int n);

#endif

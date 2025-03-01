#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> // TODO debugging
# include <stdlib.h> // malloc free
# include <unistd.h> // write
# include <math.h>
# include "mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\" ./fractol mandelbrot\" or \n\t\" ./fractol julia <x> <y>\n"
#define WIDTH	800
#define HEIGHT	800

typedef struct	s_img
{
	void	*img_ptr; // pointer to image struct
	char	*pixels_ptr; // points to the actual pixels
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx_connection; // mlx_init()
	void	*mlx_windows; // mlx_new_window()
	t_img	img;
}				t_fractal;


int		ft_strcmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);
void	fractal_init(t_fractal *fractal);

#endif

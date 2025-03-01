/*
引数について
./fractal mandelbrot
./fractol julia <real> <i>
*/

#include "fractol.h"

int main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!argv || !*argv)
		return (0);
	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strcmp(argv[1], "julia", 5)))
	{
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		printf(ERROR_MESSAGE); // TODO
		exit(1);
	}
}

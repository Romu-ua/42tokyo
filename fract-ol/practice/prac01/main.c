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
		fractal.name = argv[1];
		// 1)
		fractal_init(&fractal);
		// 2)
		fractal_render(&fractal);
		// 3)
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO)
		exit(1);
	}
}

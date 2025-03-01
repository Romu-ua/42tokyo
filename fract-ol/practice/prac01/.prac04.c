// minilibXについて学習

#include "mlx.h"
#include <stdlib.h>


#define MALLOC_ERROR    1
#define WIDTH           400
#define HEIGHT          400


int main()
{
	void	*mlx_connection;
	void	*window1;
	void	*window2;

	mlx_connection = mlx_init();
	if (mlx_connection == NULL)
		return (MALLOC_ERROR);
	window1 = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Window 1");
	if (window1 == NULL)
	{
		mlx_destroy_display(mlx_connection);
		free(window1);
		return (MALLOC_ERROR);
	}
	window2 = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Window 2");
	if (window2 == NULL)
	{
		mlx_destroy_display(mlx_connection);
		free(window1);
		return (MALLOC_ERROR);
	}
	mlx_loop(mlx_connection);
	return (0);
}

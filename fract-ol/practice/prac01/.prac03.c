// minilibXについて学習

#include "mlx.h"
#include <stdlib.h>

#define MALLOC_ERROR	1
#define WIDTH			400
#define	HEIGHT			400

int main()
{
	void	*mlx_connection;
	void	*mlx_window;

	mlx_connection = mlx_init();
	if (mlx_connection == NULL)
		return (MALLOC_ERROR);
	mlx_window = mlx_new_window(mlx_connection, HEIGHT, WIDTH, "My window");
	if (mlx_window == NULL)
	{
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		return (MALLOC_ERROR);
	}
	mlx_loop(mlx_connection);
	mlx_destroy_window(mlx_connection, mlx_window);
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
	return (0);
}

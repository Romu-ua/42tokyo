// minilibXについて学習

#include "mlx.h"
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MALLOC_ERROR		1
#define WIDTH 				400
#define HEIGHT				400

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		color;
}	t_data;

int	handle_input(int keysym, t_data *data)
{
	printf("Pressed %d\n", keysym);
	sleep(1);
	return 1;

}

int	change_color(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 150, data->color, "Color Changing Window!");
	if (data->color == 0xFF0000)
		data->color = 0x00FF00;
	else if (data->color == 0x00FF00)
		data->color = 0x0000FF;
	else
		data->color = 0xFF0000;
	return (0);
}

int	main()
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "My Window");
	data.color = 0xFF0000; // red
	mlx_key_hook(data.win_ptr, handle_input, &data);
	// mlx_loop_hookは定期的に実行される
	mlx_loop_hook(data.mlx_ptr, change_color, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

// minilibXについて学習

#include "mlx.h"
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ERROR		1
#define WIDTH 				400
#define HEIGHT				400

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	button_press(int button, int x, int y, t_data *data)
{
	if (button == 1)
		printf("Left mouse button pressed at (%d, %d)!\n", x, y);
	else if (button == 3)
		printf("Right mouse button pressed at (%d, %d)!\n", x, y);
	return (0);
}

int main()
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MALLOC_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "MLX Window");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	/*
		本来、イベントマスクを設定しないと、プログラムはイベントを受け取れない。
		mlx_key_hookについて、キーボードイベントに関しては、内部的にイベントマスクが設定されている。
		ボタンはクリックした座標が渡されている
	*/
	mlx_hook(data.win_ptr, ButtonPress, ButtonPressMask, &button_press, &data);
	mlx_loop(data.mlx_ptr);

	return (0);
}

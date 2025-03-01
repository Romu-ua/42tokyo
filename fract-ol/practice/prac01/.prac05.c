// minilibXについて学習

#include "mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>


#define MALLOC_ERROR		1
#define WIDTH 				400
#define HEIGHT				400

typedef struct	s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed \n\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed \n\n", keysym);
	return (0);
}

int main()
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MALLOC_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "My first window!");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	// hookを呼び出すと、キーボードの入力イベントを監視
	// イベントが発生するとコールバック関数handel_inputに引数を渡して実行
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

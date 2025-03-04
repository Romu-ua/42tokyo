// mlx_loop_hookについて学習

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 10000000

typedef struct s_fractol
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		x;
	int		y;
	int		iter_count;
}	t_fractol;


/*
大体１フレームあたり漸化式の計算が1000万回程度
フレームのサイズを固定するとして、800 * 600ピクセルについて計算する必要がある
48万pixel
全体の計算量が1000万pixelになるようにするから
1000/48 = 20万回計算できる
*/
int	loop_hook(t_fractol *fractol)
{
	int count;

	count = 0;
	while (fractol->x < WIDTH)
	{
		while (fractol->y < HEIGHT)
		{
			fractol->iter_count++;

			if (++count > MAX_ITER)
			{
				printf("Paused at pixel (%d, %d)\n", fractol->x, fractol->y);
				return (0);
			}
			fractol->x++;
		}
		fractol->x = 0;
		fractol->y++;
	}
	return (0);
}

int main()
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	fractol->mlx_ptr = mlx_init();
	fractol->mlx_win = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT, "My window");
	fractol->x = 0;
	fractol->y = 0;
	fractol->iter_count = 0;

	mlx_loop_hook(fractol->mlx_ptr, loop_hook, fractol);
	mlx_loop(fractol->mlx_ptr);
	return (0);
}

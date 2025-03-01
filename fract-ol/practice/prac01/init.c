#include "fractol.h"

// .prac08で実装した以下の内容を行っている
// 1.mlxの初期化
// 	vars.mlx_ptr = mlx_init();
// 2.windowを作成
// 	vars.win_ptr = mlx_new_window(vars.mlx_ptr, SIDE_LEN, SIDE_LEN, "My window");
// 3.画像のバッファを作成
// 	vars.img.img_ptr = mlx_new_image(vars.mlx_ptr, SIDE_LEN, SIDE_LEN);
// 	※ここで作成したバッファはmlx_put_image_to_window()を使わないと表示できない！
// 4.画像のバッファを取得
// 	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr,
// 												&vars.img.bits_per_pixel,
// 												&vars.img.line_len,
// 												&vars.img.endian);
// 	画像のバッファを取得して、my_pixel_putで書き込む

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	// mlx stuff
	fractal->mlx_connection = mlx_init();
	if (fractal == NULL)
		malloc_error();
	fractal->mlx_windows = mlx_new_window(fractal->mlx_connection, 
										WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_windows == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
										WIDTH, HEIGHT)
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr
												&fractal->img.bpp,
												&fractal->img.line_len,
												%fractal->img.endian);
}

// minilibXについて学習

#include "mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ERROR		1
#define SIDE_LEN			800

/*
	1.LINE_LENの計算には注意が必要
	画像の一行のバイト数を求めるときに単純に幅 * 4ではダメな場合がある
	なぜなら、メモリアライメント(効率化のための自動調整)によって一行のサイズが勝手に変化するから
	例えば、5ピクセル * ４バイト = 20バイト、だとしても実際のLINE_LENは24バイトなどに調整される可能性

	2.エンディアンは気にしなくて良い
	通常色データARGBなどを扱うときは、エンディアン(バイトの並び順)が影響することがある
	unsigned int 型の数値 0x12345678(4バイト)をメモリに保存するとき、
	ビックエンディアン 12 34 56 78
	リトルエンディアン 78 56 34 12 のようにメモリ上には保存される
	この違いは１バイトずつメモリ操作する場合に影響する
	今回はunsigned int *で扱っているため、エンディアンの違いを吸収してくれて、これらの違いを意識する必要がない
*/

typedef struct	s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_var
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_var;

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	// 座標に対応する画像バッファの適切なメモリアドレスを計算し、指定した色を格納する
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	// 画像はimg->img_pixels_ptrが指すメモリ空間にピクセルデータが並んでいる
	// 画像の先頭のポインタ(img->img_pixels_ptr)を移動させることで、目的のピクセルを指すことができている
	*((unsigned  int *)(offset + img->img_pixels_ptr)) = color;

}

void	color_screen(t_var *data, int color)
{
	for (int y = 0; y < SIDE_LEN; y++)
	{
		for (int x = 0; x < SIDE_LEN; x++)
		{
			// この関数はライブラリのものよりも高速
			// 画像をバッファに保存し、準備ができたら一括でウィンドウに転送するから。
			// ちらつき(フリッカー)が発生しない
			// ちらつきとは、描画途中で画像が更新されると、前フレームと次フレームのデータが混在して表示される現象のこと
			my_pixel_put(&data->img, x, y, color);

		}
	}
}

int	f(int keysym, t_var *data)
{
	if (keysym == XK_r)
		color_screen(data, 0xff0000);
	else if (keysym == XK_g)
		color_screen(data, 0xff00);
	else if (keysym == XK_b)
		color_screen(data, 0xff);
	else if (keysym == XK_Escape)
		exit(1);
	// 出力するのが整ったバッファ(READY image)をwindowにpush
	// 最後のパラメータは出力画像が画面のどこから表示されるのかを示したもの(e.g. 0 0 で左上)
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0 , 0);
	return (0);
}

int	main()
{
	t_var	vars;

	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		return (MALLOC_ERROR);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, SIDE_LEN, SIDE_LEN, "My window");
	if (vars.win_ptr == NULL)
	{
		mlx_destroy_display(vars.mlx_ptr);
		free(vars.mlx_ptr);
		return (MALLOC_ERROR);
	}
	// 画像のバッファを作成する関数
	vars.img.img_ptr = mlx_new_image(vars.mlx_ptr, SIDE_LEN, SIDE_LEN);
	// 画像のバッファを取得
	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr,
												&vars.img.bits_per_pixel,
												&vars.img.line_len,
												&vars.img.endian);
	printf("Line_len %d <-> SIDE_LEN %d\n"
			"bpp %d \n"
			"endian %d\n", vars.img.line_len, SIDE_LEN, vars.img.bits_per_pixel, vars.img.endian);
	mlx_key_hook(vars.win_ptr, f, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}


/*
処理の流れが混乱したので整理
1.mlxの初期化
	vars.mlx_ptr = mlx_init();
2.windowを作成
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, SIDE_LEN, SIDE_LEN, "My window");
3.画像のバッファを作成
	vars.img.img_ptr = mlx_new_image(vars.mlx_ptr, SIDE_LEN, SIDE_LEN);
	※ここで作成したバッファはmlx_put_image_to_window()を使わないと表示できない！
4.画像のバッファを取得
	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr,
												&vars.img.bits_per_pixel,
												&vars.img.line_len,
												&vars.img.endian);
	画像のバッファを取得して、my_pixel_putで書き込む
5.ボタンのアクションを監視
	mlx_key_hook(vars.win_ptr, f, &vars);
6.windowを連続で表示、イベントループ
	mlx_loop(vars.mlx_ptr);
*/

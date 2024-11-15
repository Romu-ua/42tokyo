#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// 基本の挙動
	char			c = 'a';
	char			*s = "string";
	char			*p = "pointer";
	int				d = 0x10;
	int				i = 0x10;
	unsigned	int	u = 42;
	int				x = 17;
	int				X = 17;

	printf("%c\n", c);
	printf("%s\n", s);
	printf("%p\n", p);
	printf("%d\n", d);
	printf("%i\n", i);
	printf("%u\n", -20);
	printf("%x\n", x);
	printf("%X\n", X);
	printf("%%\n");

	// 文字列の最後にNULL文字が入っていない時
	// 入ってなくてもできるんかい。どうやってやるんだ？
	char 	*str;

	str = (char *)malloc(3);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	printf("%s\n", str);

// -------------------------------------------------
	// ポインターの表示方法
	// void	*ptr = "pointer"; // 関数で受け取ってくる何某かのポインタ

	// char			*hex = "0123456789abcdef";
	// unsigned long	cast_ptr = (unsigned long)ptr; // intにキャストすると警告出る。
	// char			output[12];
	// int				j;

	// output[0] = '0';
	// output[1] = 'x';
	// j = 0;
	// while (j < 9)
	// {
	// 	output[10 - j] = hex[cast_ptr % 16];
	// 	cast_ptr /= 16;
	// 	j++;
	// }
	// output[11] = '\0';
	// printf("%s\n", output);
	// printf("%p\n", ptr);

	// 上の実装だとmacの64bitシステムにしか対応していない。32bitシステムの時は？
	void	*ptr = "test";
	char	*hex = "0123456789abcdef";
	unsigned long cast_ptr = (unsigned long)ptr;
	char	output[20];
	int		len;

	output[0] = '0';
	output[1] = 'x';
	if (!cast_ptr)
	{
		output[2] = '0';
		output[3] = '\0';
	}
	else
	{
		unsigned long temp = cast_ptr;
		len = 0;
		while (temp > 0)
		{
			temp /= 16;
			len++;
		}
		int i = len - 1; // 桁数そのものを表しているからindexの表現にするために-1している。
		while (i >= 0)
		{
			output[2 + i] = hex[cast_ptr % 16];
			cast_ptr /= 16;
			i--;
		}
		output[2 + len] = '\0';
	}
	printf("%s\n", output);
	printf("%p\n", ptr);

	printf("%p\n", NULL); // 0x0が表示される。

	char fa[5] = {'h', 'e', 'l', 'l', 'o'};
	printf("%s\n", fa); // 未定義動作 整ったメモリ領域では、NULLが他のところに入っているので、これは正しく出力される。

// -------------------------------------------------
	// xの挙動
	printf("%x\n", 42);

	// %%の挙動
	printf("%%\n");
	return (0);
}

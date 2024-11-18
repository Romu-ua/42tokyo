// vaってvariable argumentの略か

#include <stdarg.h>
#include <stdio.h>

int func(int count, ...)
{
	// 第一引数がintの時。
	int total;
	int	i;

	total = 0;
	va_list args;
	va_start(args, count); // count引数を基準に、次の引数を指している。

	i = 0;
	while (i < count)
	{
		int num = va_arg(args, int); // argsはリストなので、イテラブル
		total += num;
		i++;
	}
	va_end(args);
	return (total);
}

int	func2(int end_marker, ...)
{
	int total = 0;
	int i = 0;

	va_list args;
	va_start(args, end_marker);

	while (42)
	{
		int num = va_arg(args, int);
		if (num == end_marker)
			break;
		total += num;
	}
	va_end(args);
	return (total);
}


// --------func3--------------
int go_va_arg(va_list *args)
{
	int arg = va_arg(*args, int);
	return (arg);
}

int func3(int count, ...)
{
	va_list args;
	int 	len;
	int 	result;

	va_start(args, count);
	len = 0;
	result = 0;
	while (len < count)
	{
		int re = go_va_arg(&args); // ポインタ型で渡さないと他の変数と同様に進まない。
		result += re;
		len++;
	}
	return (result);
}

// --------------------------

int main(void)
{
	int result = func(4, 1, 1, 1, 1);
	printf("Sum is %d\n", result);
	int result2 = func2(-1, 1, 1, 1, 1, -1);
	printf("Sum is %d\n", result);
	int result3 = func3(4, 1, 2, 3, 4);
	printf("Sum is %d\n", result3);
	return (0);
}

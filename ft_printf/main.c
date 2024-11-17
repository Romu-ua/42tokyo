#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/includes/ft_printf.h"
#include "tester_func/tester.h"
#include "ft_printf/libft/libft.h"

int main(void)
{
	int	len;
	int ft_len;
// // -------------------------------------
// 	len = printf("%c\n", 'a');
// 	ft_len = ft_printf("%c\n", 'a');
// 	printf("%d %d\n", len, ft_len);
// // -------------------------------------
// 	len = printf("%s\n", "test 42");
// 	ft_len = ft_printf("%s\n", "test 42");
// 	printf("%d %d\n", len, ft_len);

// 	len = printf("%s\n", NULL);
// 	ft_len = ft_printf("%s\n", NULL);
// 	printf("%d %d\n", len, ft_len);
// // -------------------------------------
	// char	*hoge = "hogehoge";
	// len = printf("%p\n", hoge);
	// ft_len = ft_printf("%p\n", hoge);
	// printf("%d %d\n", len, ft_len);

	// len = printf("%p\n", NULL);
	// ft_len = ft_printf("%p\n", NULL);
	// printf("%d %d\n", len, ft_len);

	// // macとlinuxで挙動が違う？
	// long ho = LONG_MAX;
	// len = printf("%p\n", ho);
	// ft_len = ft_printf("%p\n", ho);
	// printf("%d %d\n", len, ft_len);

	// ho = LONG_MIN;
	// len = printf("%p\n", ho);
	// ft_len = ft_printf("%p\n", ho);
	// printf("%d %d\n", len, ft_len);

	// unsigned long h = ULONG_MAX;
	// len = printf("%p\n", h);
	// ft_len = printf("%p\n", h);
	// printf("%d %d\n", len, ft_len);

// // -------------------------------------
	len = printf("%d\n", 42);
	ft_len = ft_printf("%d\n", 42);
	printf("%d %d\n", len, ft_len);

	len = printf("%d\n", -42);
	ft_len = ft_printf("%d\n", -42);
	printf("%d %d\n", len, ft_len);

	len = printf("%d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_len = ft_printf("%d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("%d %d\n", len, ft_len);

// // -------------------------------------
// 	len = printf("%i\n", 42);
// 	ft_len = ft_printf("%i\n", 42);
// 	printf("%d %d\n", len, ft_len);
// // -------------------------------------
// 	len = printf("%u\n", -1);
// 	ft_len = ft_printf("%u\n", -1);
// 	printf("%d %d\n", len, ft_len);
// // -------------------------------------
// 	len = printf("%x\n", 42);
// 	ft_len = ft_printf("%x\n", 42);
// 	printf("%d %d\n", len, ft_len);

// 	len = printf("%x\n", NULL);
// 	ft_len = ft_printf("%x\n", NULL);
// 	printf("%d %d\n", len, ft_len);
// 	len = printf("%x\n", -42);
// 	ft_len = ft_printf("%x\n", -42);
// 	printf("%d %d\n", len, ft_len);
// // -------------------------------------
// 	len = printf("%X\n", 42);
// 	ft_len = ft_printf("%X\n", 42);
// 	printf("%d %d\n", len, ft_len);
// 	len = printf("%X\n", -1);
// 	ft_len = ft_printf("%X\n", -1);
// 	printf("%d %d\n", len, ft_len);
// // -------------------------------------
// 	len = printf("%%\n");
// 	ft_len = ft_printf("%%\n");
// 	printf("%d %d\n", len, ft_len);
// // -------------------------------------



	return (0);
}

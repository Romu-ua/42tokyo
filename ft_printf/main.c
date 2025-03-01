#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/includes/ft_printf.h"
#include "tester_func/tester.h"
#include "ft_printf/libft/libft.h"

int main()
{
// -------関数を用いたテスト----------
    // test_cmp("%s", "Hello, World!");
	// test_cmp("%c", (int)'A');
	// test_cmp("%d", 123);
	// test_cmp("%u", 3000000000u);
	// test_cmp("%x", 0xabc);
	// test_cmp("%p", NULL);

	// test_cmp("%c %c", '4', '2');

// ------手動のテスト----------------
    // %c: 文字
	int len;
	int ft_len;

    len = printf("%c %c %c %c %c\n", '4', '2', 'i', 's', '.');
    ft_len = ft_printf("%c %c %c %c %c\n", '4', '2', 'i', 's', '.');
    printf("printf len: %d, ft_printf len: %d\n", len, ft_len);

    len = printf("%c\n", 11111); // 異常値
    ft_len = ft_printf("%c\n", 11111);
    printf("printf len: %d, ft_printf len: %d\n", len, ft_len);

    // %s: 文字列
    len = printf("%s %s\n", "Hello,", "World!");
    ft_len = ft_printf("%s %s\n", "Hello,", "World!");
    printf("printf len: %d, ft_printf len: %d\n", len, ft_len);

    len = printf("%s\n", NULL); // NULL 文字列
    ft_len = ft_printf("%s\n", NULL);
    printf("printf len: %d, ft_printf len: %d\n", len, ft_len);

    // %p: ポインタ
    int x = 42;
    len = printf("%p\n", &x);
    ft_len = ft_printf("%p\n", &x);
    printf("printf len: %d, ft_printf len: %d\n", len, ft_len);

    len = printf("%p\n", NULL); // mac: 0x0 linux:(nil)となる。
    ft_len = ft_printf("%p\n", NULL);
    printf("printf len: %d, ft_printf len: %d\n", len, ft_len);

    // %d: 整数
    len = printf("%d %d %d\n", 42, -42, 0);
    ft_len = ft_printf("%d %d %d\n", 42, -42, 0);
    printf("printf len: %d, ft_printf len: %d\n", len, ft_len);

    // %i: 整数
    len = printf("%i %i %i\n", 42, -42, 0);
    ft_len = ft_printf("%i %i %i\n", 42, -42, 0);
    printf("printf len: %d, ft_printf len: %d\n", len, ft_len);

    // %u: 符号なし整数
    len = printf("%u %u %u\n", 42, 4294967295u, 0); // 0 から UINT_MAX
    ft_len = ft_printf("%u %u %u\n", 42, 4294967295u, 0);
    printf("printf len: %d, ft_printf len: %d\n", len, ft_len);

    // %x: 16進数（小文字）
    len = printf("%x %x %x\n", 42, 0xabc, 0);
    ft_len = ft_printf("%x %x %x\n", 42, 0xabc, 0);
    printf("printf len: %d, ft_printf len: %d\n", len, ft_len);

    // %X: 16進数（大文字）
    len = printf("%X %X %X\n", 42, 0xABC, 0);
    ft_len = ft_printf("%X %X %X\n", 42, 0xABC, 0);
    printf("printf len: %d, ft_printf len: %d\n", len, ft_len);

    // %%: リテラル %
    len = printf("%%\n");
    ft_len = ft_printf("%%\n");
    printf("printf len: %d, ft_printf len: %d\n", len, ft_len);

    return 0;
}

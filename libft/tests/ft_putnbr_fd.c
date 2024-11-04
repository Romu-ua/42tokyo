#include <fcntl.h>   // open関数用
#include <unistd.h>  // write関数用
#include <limits.h>  // INT_MIN用
#include <stdio.h>   // printf関数用
#include "../includes/libft.h"

// ft_putnbr_fd関数の宣言
void    ft_putnbr_fd(int n, int fd);

void    test_ft_putnbr_fd()
{
    // テストケース
    int test_cases[] = {0, -1, 1, 42, -42, 123456789, -123456789, INT_MAX, INT_MIN};
    int num_cases = sizeof(test_cases) / sizeof(int);
    int fd = STDOUT_FILENO; // 標準出力（コンソール）に出力

    printf("Testing ft_putnbr_fd function:\n");

    for (int i = 0; i < num_cases; i++)
    {
        int n = test_cases[i];
        
        // テストケースのラベルを先に出力
        printf("Input: %d, Output: ", n);
        fflush(stdout);  // 出力バッファをクリア

        // 実際の数値を ft_putnbr_fd で出力
        ft_putnbr_fd(n, fd);

        // ft_putnbr_fd の後に改行を追加
        printf("\n");
    }
}

int main()
{
    test_ft_putnbr_fd();
    return 0;
}
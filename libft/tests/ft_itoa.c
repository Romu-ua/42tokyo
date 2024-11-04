#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>  // INT_MIN, INT_MAX のためにインクルード
#include "../includes/libft.h"  // 自作の ft_itoa を使うため

// テスト用関数
void test_itoa(int n) {
    char buffer[20];  // sprintf用のバッファ
    char *ft_result;

    // 標準ライブラリの sprintf を使って整数を文字列に変換
    sprintf(buffer, "%d", n);

    // 自作の ft_itoa を使用して整数を文字列に変換
    ft_result = ft_itoa(n);

    // 結果の比較と出力
    printf("Testing ft_itoa(%d):\n", n);
    printf("Expected: %s\n", buffer);
    printf("Result:   %s\n", ft_result);

    if (ft_result == NULL) {
        printf("ft_itoa returned NULL\n");
    } else if (strcmp(buffer, ft_result) == 0) {
        printf("Test passed!\n");
    } else {
        printf("Test failed!\n");
    }

    free(ft_result);  // ft_itoa で割り当てたメモリを解放
    printf("-----------\n");
}

int main(void) {
    // テストケースのセットアップ
    int test_values[] = {0, 1, -1, 123, -123, INT_MAX, INT_MIN, -42};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    // 各テストケースで test_itoa を実行
    for (int i = 0; i < num_tests; i++) {
        test_itoa(test_values[i]);
    }

    return 0;
}

#include <stdio.h>   // printf を使うため
#include <string.h>  // 本家 strlen のため
#include "../includes/libft.h"  // 自作の ft_strlen を使うため

void run_tests() {
    // テスト用文字列の配列
    const char *test_cases[] = {
        "",                  // 空文字列
        "42",                // 短い文字列
        "Hello, world!",     // 一般的な文字列
        "The quick brown fox jumps over the lazy dog.",
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
        NULL                 // NULL ポインタ（特にテスト）
    };

    int passed = 1;  // テストの成功フラグ

    // 各テストケースで strlen と ft_strlen の結果を比較
    for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        const char *str = test_cases[i];

        if (str == NULL) {
            printf("Skipping NULL test case to avoid undefined behavior.\n");
            continue;
        }

        size_t result_original = strlen(str);
        size_t result_custom = ft_strlen(str);

        if (result_original != result_custom) {
            printf(
                "Test failed: input = \"%s\", expected = %zu, got = %zu\n",
                str, result_original, result_custom
            );
            passed = 0;
        }
    }

    // テスト結果の表示
    if (passed) {
        printf("All tests passed!\n");
    } else {
        printf("Some tests failed.\n");
    }
}

int main(void) {
    run_tests();
    return 0;
}

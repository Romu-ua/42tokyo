#include <stdio.h>
#include <ctype.h>     // 標準ライブラリの isprint を使うため
#include "../includes/libft.h"  // 自作の ft_isprint を使うため

void run_tests() {
    // テストする文字のリスト (制御文字と印刷可能な文字を含む)
    int test_chars[] = {
        'A', 'z', '0', '9', '!', ' ', '\n', 127
    };

    int passed = 1;  // テストの成功フラグ

    // 各文字に対してテストを実行
    for (size_t i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++) {
        int c = test_chars[i];

        // 本家 isprint と自作 ft_isprint の結果を比較
        int result_original = isprint(c);
        int result_custom = ft_isprint(c);

        if (result_original != result_custom) {
            printf(
                "Test failed: input = '%c' (ASCII: %d), "
                "expected = %d, got = %d\n",
                c, c, result_original, result_custom
            );
            passed = 0;
        }
    }

    // 結果の出力
    if (passed) {
        printf("All tests passed!\n");
    }
}

int main(void) {
    run_tests();
    return 0;
}

#include <stdio.h>
#include <ctype.h>
#include "../includes/libft.h"

void run_tests() {
    int test_chars[] = {
        'A', 'z', '0', '9', '!', ' ', 128
    };

    int passed = 1;  // テスト成功フラグ

    // 各文字に対してテストを実行
    for (size_t i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++) {
        int c = test_chars[i];

        // 本家 isalnum と自作 ft_isalnum の結果を比較
        int result_original = isalnum(c);
        int result_custom = ft_isalnum(c);

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

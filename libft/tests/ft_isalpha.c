#include <stdio.h>
#include "../includes/libft.h"

typedef struct {
    int input;
    int expected;
} TestCase;

TestCase tests[] = {
    {'A', 1},
    {'z', 1},
    {'0', 0},
    {'!', 0},
    {42, 0}
};

void run_tests() {
    int passed = 1; // 成功フラグ
    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        int result = ft_isalpha(tests[i].input);
        if (result != tests[i].expected) {
            printf("Test failed: input = '%c', expected = %d, got = %d\n",
                tests[i].input, tests[i].expected, result);
            passed = 0;
        }
    }

    if (passed) {
        printf("All tests passed!\n");
    }
}


int main() {
    run_tests();
    return 0;
}

#include <stdio.h>
#include <ctype.h>
#include "../includes/libft.h"

void run_tests() {
	int test_chars[] = {
		'1', 'a', 'f', 0, 0177, 0111111
	};

	int passed = 1;

	for (size_t i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++) {
		int c = test_chars[i];

		int result_original = isascii(c);
		int result_custom = ft_isascii(c);

		if (result_original != result_custom) {
			printf(
				"Test failed: input = '%c' (ASCII: %d), "
                "expected = %d, got = %d\n",
                c, c, result_original, result_custom
			);
			passed = 0;
		}
	}

	if (passed) {
		printf("All tests passed!\n");
	}
}

int main(void) {
	run_tests();
	return 0;
}

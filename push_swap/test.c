#include <stdio.h>

typedef enum e_op
{
    sa,
    sb,
    pa,
    pb,
    ra,
    rb,
    rra,
    rrb
} t_op;

int main()
{
    printf("Size of t_op: %zu bytes\n", sizeof(t_op));  // 4 バイトの可能性が高い
    return 0;
}

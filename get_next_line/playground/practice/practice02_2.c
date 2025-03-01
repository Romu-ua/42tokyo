#include <stdio.h>

extern int practice01;

void other_modify()
{
	practice01 += 10;
	printf("%d\n", practice01);
}

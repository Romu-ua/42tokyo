#include <stdio.h>
#include "ft_printf/includes/ft_printf.h"

int main(void)
{
	char			c = 'c';
	char			*s = "test";
	char			*p = "ptr";
	int				d = 42;
	int				i = 444222;
	unsigned int	u = 42;
	int				x = 1024;
	int				X = 1024;


	// c sは一旦パス
	ft_printf("%c%s42\n", c, s);
	printf("%c%s\n", c, s);

	// p
	ft_printf("%p\n", p);
	printf("%p\n", p);

	// d i u
	ft_printf("%d \n", d);
	printf("%d \n", d);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	ft_printf("%u\n", u);
	printf("%u\n", u);

	//x X
	ft_printf("%x\n", x);
	printf("%x\n", x);
	ft_printf("%X\n", X);
	printf("%X\n", X);

	//%
	ft_printf("%%\n");
	printf("%%\n");

	return (0);
}

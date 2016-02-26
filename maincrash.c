#include "ft_printf.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

#include <stdio.h> /* !!! */

typedef unsigned long long		ull;
typedef long long				ll;
typedef unsigned long			ul;

typedef enum		e_modifier
{
	NONE,
	HH,
	H,
	L,
	LL,
	J,
	T,
	Z
}
;
void	ft_print_result(int mr, int or, int line)
{
	static int c = 0;
	printf("\033[33m[%d]\033[0m MINE = %i - ORIG = %i", c, mr, or);
	if (mr == or)
		printf("\t\033[32m✔\033[0m");
	else
		printf("\t\033[31m✘ - (failed between lines %i and %i)\033[0m",
			   line - 3, line);
	printf("\n---------------\n");
	c++;
}

int	main(void)
{
	int	or, mr;
	char	**test;

	test = malloc(sizeof(char*));
	or = 0;
	mr = 0;


mr = ft_printf("MINE>d 2147483648\t[%d]\n", 2147483648);
	or = printf("ORIG>d 2147483648\t[%d]\n", 2147483648);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>5.d 5.0d 0 0\t[%5.d], [%5.0d]\n", 0, 0);
	or = printf("ORIG>5.d 5.0d 0 0\t[%5.d], [%5.0d]\n", 0, 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>5.d 5.0d 1 1\t[%5.d], [%5.0d]\n", 1, 1);
		or = printf("ORIG>5.d 5.0d 1 1\t[%5.d], [%5.0d]\n", 1, 1);
		ft_print_result(mr, or, __LINE__);


mr = ft_printf("MINE>u -1\t[%u]\n", -1);
	or = printf("ORIG>u -1\t[%u]\n", -1);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>u 4294967296\t[%u]\n", 4294967296);
	or = printf("ORIG>u 4294967296\t[%u]\n", 4294967296);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>.10d -42\t[%.10d]\n", -42);
	or = printf("ORIG>.10d -42\t[%.10d]\n", -42);
	ft_print_result(mr, or, __LINE__);

/*
	ft_printf("MINE>\t");
	ft_printf("% Z%s", "test");
	ft_printf("\n");

	printf("ORIG>\t");
	printf("% Z%s", "test");
	printf("\n");

mr = ft_printf("MINE>\t[% Z%s]\n", "test");
	or = printf("ORIG>\t[% Z%s]\n", "test");
	ft_print_result(mr, or, __LINE__);
*/

mr = ft_printf("MINE>03.2d 0\t[%03.2d]\n", 0);
or = printf("ORIG>03.2d 0\t[%03.2d]\n", 0);
ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>03.2d 1\t[%03.2d]\n", 1);
or = printf("ORIG>03.2d 1\t[%03.2d]\n", 1);
ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>\t[%03.2d]\n", -1);
or = printf("ORIG>\t[%03.2d]\n", -1);
ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>\t[%06.2d]\n", -1);
or = printf("ORIG>\t[%06.2d]\n", -1);
ft_print_result(mr, or, __LINE__);

ft_print_result(mr, or, __LINE__);
mr = ft_printf("MINE>###-#0000 33...12..#0+0d 256\t[%###-#0000 33...12..#0+0d]\n", 256);
or = printf("ORIG>###-#0000 33...12..#0+0d 256\t[%###-#0000 33...12..#0+0d]\n", 256);
ft_print_result(mr, or, __LINE__);

    return (0);
}

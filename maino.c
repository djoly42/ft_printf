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
		printf("\033[1;37m======== %%o ========\033[0m\n");

	mr = ft_printf("MINE>\t[%o]\n", 2048);
	or = printf("ORIG>\t[%o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% o]\n", 777);
	or = printf("ORIG>\t[% o]\n", 777);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+o]\n", 128);
	or = printf("ORIG>\t[%+o]\n", 128);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-o]\n", 48);
	or = printf("ORIG>\t[%-o]\n", 48);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+5o]\n", 10);
	or = printf("ORIG>\t[%+5o]\n", 10);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-5o]\n", 2048);
	or = printf("ORIG>\t[%-5o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+10o]\n", 2048);
	or = printf("ORIG>\t[%+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%010o]\n", 2048);
	or = printf("ORIG>\t[%010o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-+10o]\n", 2048);
	or = printf("ORIG>\t[%-+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-0+10o]\n", 2048);
	or = printf("ORIG>\t[%-0+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#o]\n", 48);
	or = printf("ORIG>\t[%#o]\n", 48);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#+10o]\n", 2048);
	or = printf("ORIG>\t[%#+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-0+10o]\n", 2048);
	or = printf("ORIG>\t[%-0+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-0+10o]\n", 2048);
	or = printf("ORIG>\t[%-0+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);


	mr = ft_printf("MINE>\t[%#-0+10o]\n", 2048);
	or = printf("ORIG>\t[%#-0+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-0#+3o]\n", 2048);
	or = printf("ORIG>\t[%-0#+3o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%o]\n", 02047);
	or = printf("ORIG>\t[%o]\n", 02047);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%o]\n", 02047);
	or = printf("ORIG>\t[%o]\n", 02047);
	ft_print_result(mr, or, __LINE__);

	printf("\033[1;37m======== end %%o =====\033[0m\n\n");


	mr = ft_printf("MINE>\t[%5.4o]\n", 10);
	or = printf(   "ORIG>\t[%5.4o]\n", 10);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-8.6o]\n", 0456);
	or = printf(   "ORIG>\t[%-8.6o]\n", 0456);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%18.12o]\n", 0777777777);
	or = printf(   "ORIG>\t[%18.12o]\n", 0777777777);
	ft_print_result(mr, or, __LINE__);

    return (0);
}

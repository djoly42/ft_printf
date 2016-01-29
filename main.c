/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 10:54:56 by daniel            #+#    #+#             */
/*   Updated: 2016/01/29 15:12:09 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#define MINE ft_printf
#define ORIG printf
int main ()
{

  int mr;
  int or;

	printf("======== %%c ========\n");
	mr = ft_printf("MINE>\t[%c]\n", 'H');
	or = printf("ORIG>\t[%c]\n", 'H');
//	printf("mr:%d or:%d\n",mr, or);

	mr = ft_printf("MINE>3c\t[%2c]\n", 'r');
	or = printf("ORIG>3c\t[%2c]\n", 'r');
//	printf("mr:%d or:%d\n",mr, or);

	mr = ft_printf("MINE>+3c\t[%+3c]\n", 'r');
	or = printf("ORIG>+3c\t[%+3c]\n", 'r');
//	printf("mr:%d or:%d\n",mr, or);

//	printf("mr:>>%-3.+4d<<or:\n",42);
	mr = ft_printf("MINE>-3c\t[%-3c]\n", 'r');
	or = printf("ORIG>-3c\t[%-3c]\n", 'r');
//	printf("mr:%d or:%d\n",mr, or);

	mr = ft_printf("MINE>-10c\t[%-10c]\n", 'r');
	or = printf("ORIG>-10c\t[%-10c]\n", 'r');
	//printf("mr:%d or:%d\n",mr, or);

	mr = ft_printf("MINE>010c\t[%010c]\n", 'r');
	or = printf("ORIG>010c\t[%010c]\n", 'r');
	//printf("mr:%d or:%d\n",mr, or);

	mr = ft_printf("MINE>+-10c\t[%+-10c]\n", 'r');
	or = printf("ORIG>+-10c\t[%+-10c]\n", 'r');
	//printf("mr:%d or:%d\n",mr, or);

	mr = ft_printf("MINE>0+10c\t[%0+10c]\n", 'r');
	or = printf("ORIG>0+10c\t[%0+10c]\n", 'r');
//	printf("mr:%d or:%d\n",mr, or);

/* 	========c AVEC * ============
	mr = ft_printf("MINE>\t[%*c]\n", 8, 'c');
	or = printf(   "ORIG>\t[%*c]\n", 8, 'c');
	printf("mr:%d or:%d\n",mr, or);


	mr = ft_printf("MINE>\t[%-*c]\n", 8, 'k');
	or = printf(   "ORIG>\t[%-*c]\n", 8, 'k');
	printf("mr:%d or:%d\n",mr, or);
*/
	mr = ft_printf("MINE>5.4c\t[%5.2c]\n", 'k');
	or = printf(   "ORIG>5.4c\t[%5.2c]\n", 'k');
//	printf("mr:%d or:%d\n",mr, or);

	mr = ft_printf("MINE>-5.4c\t[%-5.4c]\n", 'k');
	or = printf(   "ORIG>-5.4c\t[%-5.4c]\n", 'k');
//	printf("mr:%d or:%d\n",mr, or);
/*		lc == C
	ft_printf("%lc, %lc", L'暖', L'ح');
	printf("%lc, %lc", L'暖', L'ح');
//	printf("mr:%d or:%d\n",mr, or);
*/

	ft_printf("MINE>#c>\t[%#c]\n", 0);
	printf("ORIG>#c>\t[%#c]\n", 0);
//	printf("mr:%d or:%d\n",mr, or);

	ft_printf("MINE>+c\t[%+c]\n", 0);
	printf("ORIG>+c\t[%+c]\n", 0);
//	printf("mr:%d or:%d\n",mr, or);

	ft_printf("MINE>.c\t[%.c]\n", 0);
	printf("ORIG>.c\t[%.c]\n", 0);
//	printf("mr:%d or:%d\n",mr, or);

	ft_printf("MINE>.5c\t[%.5c]\n", 0);
	printf("ORIG>.5c\t[%.5c]\n", 0);
//	printf("mr:%d or:%d\n",mr, or);

	ft_printf("MINE>.5c\t[%.5c]\n", 42);
	printf("ORIG>.5c\t[%.5c]\n", 42);
	printf("mr:%d or:%d\n",mr, or);

	ft_printf("MINE>c\t[%c]\n", 200);
	printf("ORIG>c\t[%c]\n", 200);

//	printf("======== end %%c =====\n\n");

	//printf("abc")
	printf("|%d|\n",12345);
	ft_printf("|%d|\n",12345);
	printf("|%+d|\n",12345);
	ft_printf("|%+d|\n",12345);
	printf("|%8d|\n",12345);
	ft_printf("|%8d|\n",12345);
	printf("|%x|\n",255);
	ft_printf("|%x|\n",255);
	printf("|%X|\n",255);
	ft_printf("|%X|\n",255);
	printf("|%#x|\n",255);
	ft_printf("|%#x|\n",255);
    printf("|%f|\n",1.213456789102345);
    ft_printf("|%f|\n",1.213456789102345);
    printf("|%10.4f|\n",1.213456789);
    ft_printf("|%10.4f|\n",1.213456789);

    printf("printf:|%4d|%2d|\n",123,123);
	ft_printf("ft_printf:|%d|%d|\n",123,123);
    ft_printf("|abc|%%|%d|%c|\n",0,'1');

    return (0);
}

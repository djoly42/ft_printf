/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:30:41 by djoly             #+#    #+#             */
/*   Updated: 2016/01/29 14:03:55 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//sSpdDioOuUxXcC 14

void    ft_init_env(t_env *env)//, const char *format)
{
	int i;

	i = 0;
	//ft_putchar('C');
    FONCT = ft_init_list();

    IFOR = 0;
    ITOK = 0;
    NBR = -1;
	NBRPREC = -1;
	//ft_putchar('C');
	//FNDFLAGS = malloc(sizeof(char *));
	while (i < 10)
	{
		FNDFLAGS[i] = -1;
		i++;
	}
    //FLAGS = ft_memset(FLAGS, 0, 10);
    RET = 0;
	//ft_putchar('C');
}

t_tab   *ft_init_list()
{
    t_tab   *t_token;
    t_tab   *beg;
	//ft_putchar('B');
    t_token = (t_tab*)malloc(sizeof(t_tab*) * 14);
	//ft_putchar('B');
    beg = t_token;
    //t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 's';
	//t_token->fonction = fonct_s;
    t_token++;
    //t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 'S';
	//t_token->fonction = fonct_S;
    t_token++;
 	//t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 'p';
	//t_token->fonction = fonct_p;
    t_token++;
    //t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 'd';
	//t_token->fonction = fonct_d;
    t_token++;
    //t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 'D';
	//t_token->fonction = fonct_D;
    t_token++;
    //t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 'i';
	//t_token->fonction = fonct_i;
    t_token++;
    //t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 'o';
	//t_token->fonction = fonct_o;
    t_token++;
 	//t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 'O';
	//t_token->fonction = fonct_O;
    t_token++;
	//ft_putchar('B');
    //t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 'u';
	//t_token->fonction = fonct_u;
    t_token++;
    //t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 'U';
	//t_token->fonction = fonct_U;
    t_token++;
    //t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 'x';
	//t_token->fonction = fonct_x;
      t_token++;
    //t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 'X';
	//t_token->fonction = fonct_X;
    t_token++;
    //t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 'c';
	t_token->fonction =  fonct_c;
    t_token++;
    //t_token = (t_tab*)malloc(sizeof(t_tab*));
	t_token->c = 'C';
	//ft_putchar('B');
	//t_token->fonction = fonct_C;
    return (beg);
}

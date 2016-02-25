/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:40:46 by djoly             #+#    #+#             */
/*   Updated: 2016/02/24 09:57:06 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int     ft_check_nbr(t_env *env)
{
	/* 4 ok
	ft_putstr("FORMAT==");
	ft_putchar(FORMAT[IFOR]);
	ft_putstr("<<<\n");
	*/
	if (FORMAT[IFOR] >= '1' && FORMAT[IFOR] <= '9' )
	{

		if (FNDFLAGS[9] == 1)
		IFOR = IFOR + ft_nbrlen((NBRPREC = ft_atoi(&FORMAT[IFOR])));
		else
		IFOR = IFOR + ft_nbrlen((NBR = ft_atoi(&FORMAT[IFOR])));
		/*nbr 4 ok
		ft_putstr("NBR==");
		ft_putnbr(NBR);
		ft_putstr("<<<");
		*/
		/* 1 ok
		ft_putstr("NBRLEN==");
		ft_putnbr(ft_nbrlen(NBR));
		ft_putstr("<<<");
		*/

		//ft_putstr(">>>>FIN<<<<");
		return (1);
	}
	return (0);
}

int     ft_check_flags(t_env *env)
{
    int     ifind;
    char    *find;
    ifind = 0;
	//ft_putstr("FORMAT>>>");
	   /*ft_putchar(FORMAT[IFOR]);
	   ft_putstr("<<<");
etourne 3 OK
	   */
	if ((find = ft_strchr(FLAGS,FORMAT[IFOR])))
	{
		//ft_putstr(">>>INIF<<<");
		//ft_putchar(ARG);
	ifind = find - FLAGS;
	/*
	ft_putstr(">>>IFIND>>>");
	   ft_putnbr(ifind);
	   ft_putstr("<<<");
*/
		//ft_putstr(">>>INIF<<<");
		if (ifind == 5 && FORMAT[IFOR + 1] == 'h')
		{
			FNDFLAGS[ifind] = 2;
			IFOR = IFOR + 1;
		}
		else if (ifind == 6 && FORMAT[IFOR + 1] == 'l')
        {
            FNDFLAGS[ifind] = 2;
			IFOR = IFOR + 1;
		}	
        else
			FNDFLAGS[ifind] = 1;
		IFOR = IFOR + 1;
		//ft_putstr(">>>>LOVE<<<<");
		return (1);
	}
	//ft_putstr(">>>>HATE<<<<");
    return (0);
}
int 	ft_check_token(t_env *env)
{
    char    *find;
    int     ifind;

	IFOR = IFOR + 1;
    ifind = 0;
    ARG = va_arg(AP, void *);
	//retourne 3 OK
  /* 	ft_putstr("FORMAT>>>");
   	ft_putchar(FORMAT[IFOR]);
   	ft_putstr("<<<");
	*/
	while (!(find = ft_strchr(TOKEN,FORMAT[IFOR])))
	{
		if (FORMAT[IFOR] == '\0')
		{
			ft_putstr("find|");
			return (0);
		}/*find 0 ok
		  ft_putstr("find|");
		  ft_putnbr(find);
		  ft_putchar('|');
		 */
/*
		ft_putstr(">>>FORNAT[IFOR]>>>");
		ft_putchar(FORMAT[IFOR]);
		ft_putstr("<<<\n");
*/
		if ( !(ifind = ft_check_nbr(env)))//))
		{
			//ft_putstr(">>>DANS IF<<<\n");
			ifind = ft_check_flags(env);
		}

		if (!(ifind))
		{
			if (FORMAT[IFOR] == '%')
			{
				print_percent(env);
			//	IFOR = IFOR + 1;
			}
			else {
			ft_putstr(">>char non reconue>>");
			ft_putchar(FORMAT[IFOR]);
			ft_putstr("<<");
			}
			IFOR = IFOR + 1;
		}
		if (FORMAT[IFOR] == '\0')
		{
			//ft_putstr("find|");
			return (0);
		}
		//IFOR = IFOR + ifind;
		// c 1 0k  +3cOK
		/*
		   ft_putstr("ifind>>>");
		   ft_putnbr(ifind);
		   ft_putstr("<<<");
		 */
		//	 ft_putstr("HATE");
		//		return (-1);
		//}
	}
// TEST FLAG TROUVER
/*
ft_putstr("FNDFLAGS>>>");
ft_putnbr(FNDFLAGS[3]);
ft_putstr("<<<");
*/
	ITOK = find - TOKEN;
/*
ft_putstr("NBR>>");
ft_putnbr(NBR);
ft_putstr("<<");
ft_putstr("NBRPREC>>");
ft_putnbr(NBRPREC);
ft_putstr("<<");
*/
//ft_putchar('D');
	//ft_putnbr(ITOK);
	env->fonction[ITOK](env); // deconne 3
	return (1);
}

void    run_format(t_env *env)
{
//ft_putstr(env->format);
    while (FORMAT[IFOR] != '\0')
	{
		//ft_putchar('A');
		//ft_putchar(FORMAT[IFOR]);
		if (FORMAT[IFOR] == '%')
		{
		//	ft_putstr("1");
			if (FORMAT[IFOR + 1] == '%')
			{
				RET = RET + ft_putchar('%');
				IFOR = IFOR + 1;
			}
			else
				ft_check_token(env);
				if (FORMAT[IFOR] == '\0')
					return ;
				ft_re_init_env(env);
		}
		else
		{
	//ft_putstr("RET>>");
	//ft_putnbr(RET);
			RET = RET + ft_putchar(FORMAT[IFOR]);
		}
		IFOR = IFOR + 1;
		//ft_putstr("boucle");

	}
}

int     ft_printf(const char *format, ...)
{
	//va_list		pa;
	//void *a;
//ft_putstr(format);
	t_env		env;

	//env = malloc(sizeof(t_env *));
	env.format = format;
    ft_init_env(&env);
	va_start(env.ap, format);
	//ARG = va_arg(AP, void*);
	//ft_putchar(ARG);
    run_format(&env);
	va_end(env.ap);
//	free(env);
	return (env.ret);
}

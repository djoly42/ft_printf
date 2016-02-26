/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:03:36 by djoly             #+#    #+#             */
/*   Updated: 2016/02/26 10:07:05 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long int     ft_octalnbr(unsigned long  int nb)
{
    if (nb > 7)
        return ((nb % 8) + 10 * ft_octalnbr(nb / 8));
    return (nb);
}

static void x_prec(t_env *env)
{
	if (NBRPREC != -1 )
	{
		if (FNDFLAGS[2] != 1 && FNDFLAGS[9] == 1 && NBR != -1) // pas de -
			RET = RET + ft_putspace(NBR - NBRPREC);
		if (NBRPREC > env->arglen )//.
			RET = RET + ft_putzero2(NBRPREC - env->arglen);
		RET = RET + ft_putnbr(ft_octalnbr((unsigned long int)ARG));
		if (FNDFLAGS[2] == 1 && FNDFLAGS[9] == 1 && NBR > NBRPREC)// -
			RET = RET + ft_putspace(NBR - NBRPREC);
	}
	else if(NBR != -1)
	{
		if (FNDFLAGS[0] == 1)
		{
			if ((unsigned long int)ARG != 0)
			{
				RET = RET + ft_putspace(NBR - 1 - ARGLEN);
				RET = RET + ft_putchar('0');
			}
			else
				RET = RET + ft_putspace(NBR - 1);
			RET = RET + ft_putnbr(ft_octalnbr((unsigned long int)ARG));
		}
		else
			RET = RET + ft_putspace(NBR);
	}
	else if (FNDFLAGS[0] == 1)
	{
		if ((unsigned long int)ARG != 0)
			RET = RET + ft_putchar('0');
		RET = RET + ft_putnbr(ft_octalnbr((unsigned long int)ARG));
	}
}
int                     fonct_o(t_env *env)
{
	env->arglen = ft_unbrlen(ft_octalnbr((unsigned int)ARG));
	//ft_putnbr(env->arglen);
	if (FNDFLAGS[9] == 1)
		x_prec(env);
	else
	{

		if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == -1 && NBR != -1) // pas de - et nbr pas de 0
		{
			if (FNDFLAGS[0] == 1)
			NBR = NBR - 1;
			RET = RET + ft_putspace(NBR - env->arglen);
		}

		if (FNDFLAGS[2] != 1 && FNDFLAGS[1] == 1 && NBR != -1)
		RET = RET + ft_putzero2(NBR - env->arglen);
		if (FNDFLAGS[0] == 1)
		RET = RET + ft_putzero2(1);
		RET = RET + ft_putnbr(ft_octalnbr((unsigned long int)ARG));
		// ft_putnbr(RET);

		if (FNDFLAGS[2] == 1 && NBR != -1 && NBR > env->arglen) // - et nbr
		{
			if (FNDFLAGS[0] == 1)
			NBR = NBR - 1;
			RET = RET + ft_putspace(NBR - env->arglen);
		}
	}
    //ft_putnbr(RET);
return (1);
}

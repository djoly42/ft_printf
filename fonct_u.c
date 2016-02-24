/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:03:36 by djoly             #+#    #+#             */
/*   Updated: 2016/02/24 16:36:23 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void x_prec(t_env *env)
{
	if (FNDFLAGS[2] != 1 && FNDFLAGS[9] == 1 && NBR != -1 &&  NBRPREC != -1 ) //.
    	RET = RET + ft_putspace(NBR - NBRPREC);
	if (NBRPREC != -1 && NBRPREC > env->arglen )//.
		RET = RET + ft_putzero2(NBRPREC - env->arglen);
    RET = RET + ft_putnbr((unsigned int)ARG);
	if (FNDFLAGS[2] == 1 && FNDFLAGS[9] == 1 && NBRPREC != -1 && NBR != -1)//.
	    RET = RET + ft_putspace(NBR - NBRPREC);




}

int                     fonct_u(t_env *env)
{
	env->arglen = ft_unbrlen((unsigned int)ARG);
 //ft_putnbr(env->arglen);
	if (FNDFLAGS[9] == 1)
		x_prec(env);
	else
	{
    if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == -1 && NBR > ARGLEN) // pas de - et nbr pas de 0
		RET = RET + ft_putspace(NBR - env->arglen);
    if (FNDFLAGS[2] != 1 && FNDFLAGS[1] == 1 && NBR != -1)
	    RET = RET + ft_putzero2(NBR - env->arglen);
    RET = RET + ft_putnbr((unsigned int)ARG);
   // ft_putnbr(RET);

	if (FNDFLAGS[2] == 1 && NBR != -1 && NBR > env->arglen && FNDFLAGS[9] == -1) // - et nbr
		RET = RET + ft_putspace(NBR - env->arglen);
	}
    //ft_putnbr(RET);
return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:03:36 by djoly             #+#    #+#             */
/*   Updated: 2016/02/18 15:32:27 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_octalnbr(unsigned long int nb)
{
    if (nb > 7)
        return ((nb % 8) + 10 * ft_octalnbr(nb / 8));
    return (nb);
}


int                     fonct_o(t_env *env)
{
	env->arglen = ft_unbrlen((unsigned long int)ARG);
 //ft_putnbr(env->arglen);
    if (FNDFLAGS[2] != 1 && FNDFLAGS[9] == 1 && NBR != -1 &&  NBRPREC != -1 ) //.
    	RET = RET + ft_putspace(NBR - NBRPREC);
    else if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == -1 && NBR != -1) // pas de - et nbr pas de 0
		RET = RET + ft_putspace(NBR - env->arglen);
    if (NBRPREC != -1 && NBRPREC > env->arglen )//.
	    RET = RET + ft_putzero2(NBRPREC - env->arglen);
    if (FNDFLAGS[2] != 1 && FNDFLAGS[1] == 1 && NBR != -1)
	    RET = RET + ft_putzero2(NBR - env->arglen);
    RET = RET + ft_putnbr(ft_octalnbr((unsigned long int)ARG));
   // ft_putnbr(RET);
    if (FNDFLAGS[2] == 1 && FNDFLAGS[9] == 1 && NBRPREC != -1 && NBR != -1)//.
	    RET = RET + ft_putspace(NBR - NBRPREC);
    else if (FNDFLAGS[2] == 1 && NBR != -1 && NBR > env->arglen && FNDFLAGS[9] == -1) // - et nbr
		RET = RET + ft_putspace(NBR - env->arglen);

    //ft_putnbr(RET);
return (1);
}

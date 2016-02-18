/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:03:36 by djoly             #+#    #+#             */
/*   Updated: 2016/02/18 15:32:27 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int                     fonct_u(t_env *env)
{
	env->arglen = ft_nbrlen((unsigned int)ARG);
	if (FNDFLAGS[2] == -1 && NBR != -1)
		RET = RET + ft_putspace(NBR - env->arglen);
	RET = RET + ft_putnbr((unsigned int)ARG);
	if (FNDFLAGS[2] == 1 && NBR != -1)
		RET = RET + ft_putspace(NBR - env->arglen);

return (1);
}

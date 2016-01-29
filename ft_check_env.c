/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 11:48:11 by djoly             #+#    #+#             */
/*   Updated: 2016/01/29 13:46:23 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putspace(t_env *env)
{
	int i;

	i = -1;
	while (++i < (NBR - 1))
	 RET = RET + ft_putchar(' ');

}
void	ft_putzero(t_env *env)
{
	int i;

	i = -1;
	while (++i < (NBR - 1))
	 RET = RET + ft_putchar('0');

}

void	ft_check_env(t_env *env)
{
	if (NBR != -1 && ITOK == 12)
		if (FNDFLAGS[1] == 1)
			ft_putzero(env);
		else
			ft_putspace(env);
	//if (NBR != -1 && FNDFLAGS[2] == 1 && ITOK == 12)

}
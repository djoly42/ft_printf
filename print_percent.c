/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 09:27:34 by djoly             #+#    #+#             */
/*   Updated: 2016/02/24 09:57:59 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_percent(t_env *env)
{
	if (FNDFLAGS[2] == -1 && NBR != -1)
		RET = RET + ft_putspace(NBR - 1);
	//else if (FNDFLAGS[4] == 1)
	//	RET = RET + ft_putchar(' ');
	RET = RET + ft_putchar('%');
	if (FNDFLAGS[2] == 1 && NBR != -1)
		RET = RET + ft_putspace(NBR - 1);
}

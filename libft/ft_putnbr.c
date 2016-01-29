/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:09:51 by djoly             #+#    #+#             */
/*   Updated: 2016/01/26 20:35:27 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nbr)
{
	int	ret;

	ret = 0;
	if (nbr == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
			ret++;
		}
		if (nbr >= 10)
		{
			ret = ret + ft_putnbr(nbr / 10);
			ret = ret + ft_putnbr(nbr % 10);
		}
		else
		{
			ret = ret + ft_putchar(nbr + '0');
		}
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:22:46 by djoly             #+#    #+#             */
/*   Updated: 2016/01/26 17:25:39 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_list(t_t_list *t_token)
{
	t_t_list	*t2;
	int			a;

	t2 = (t_t_list*)malloc(sizeof(t_t_list));
	t_token->c = 'c';
	t_token->fonction = ft_putchar;
	t_token->next = t2;
	t2->c = 'd';
	t2->fonction = ft_putnbr;
	t2->next = NULL;
}
/*
ft_token(const char *format, va_list *ap)
{


}
*/

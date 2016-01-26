/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:30:41 by djoly             #+#    #+#             */
/*   Updated: 2016/01/26 19:39:46 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf2.h"

void	ft_init_list(t_tab **t_token)
{
	t_tab	*t1;
	t_tab	*t2;
//ft_putstr("beforemalloc\n");
	t1 = (t_tab*)malloc(sizeof(t_tab));
//	ft_putstr("beforemalloc2\n");
	t2 = (t_tab*)malloc(sizeof(t_tab));
//ft_putstr("apres\n");
	t_token[0][0] = *t1;
//	ft_putstr("aprest1\n");
	t_token[0][0].c = 'c';
//		ft_putstr("apres c \n");
	t_token[0][0].fonction = ft_putchar;
//		ft_putstr("apresfonction\n");
//	t_token[0]->next = t2;
	t_token[0][1] = *t2;
//		ft_putstr("aprest2\n");
	t_token[0][1].c = 'd';
//		ft_putstr("apresc\n");
	t_token[0][1].fonction = ft_putnbr;
//		ft_putstr("apresfonction\n");
//	t_token[1]->next = t2;
/*	t2->c = 'd';
	t2->fonction = ft_putnbr;
	t2->next = NULL;*/
}
/*
void	ft_init_list(t_tab *t_token)
{
	t_tab	*t1;
	t_tab	*t2;
//ft_putstr("beforemalloc\n");
	t1 = (t_tab*)malloc(sizeof(t_tab));
//	ft_putstr("beforemalloc2\n");
	t2 = (t_tab*)malloc(sizeof(t_tab));
//ft_putstr("apres\n");

	t_token[0] = *t1;

//	ft_putstr("aprest1\n");
	t_token[0].c = 'c';
//		ft_putstr("apres c \n");
	t_token[0].fonction = ft_putchar;
//		ft_putstr("apresfonction\n");
//	t_token[0]->next = t2;

	t_token[1] = *t2;

//		ft_putstr("aprest2\n");
	t_token[1].c = 'd';
//		ft_putstr("apresc\n");
	t_token[1].fonction = ft_putnbr;
//		ft_putstr("apresfonction\n");
//	t_token[1]->next = t2;

}
*/
/*
ft_token(const char *format, va_list *ap)
{


}
*/

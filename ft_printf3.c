/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:40:46 by djoly             #+#    #+#             */
/*   Updated: 2016/01/26 20:13:15 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf2.h"
#include <stdio.h>

void ft_check_token(const char *format, va_list *ap, t_tab *t_token)
{
	void *a;
	a = va_arg(*ap, void *);
	int		i;
	i = 0;
	while (i < 2)
	{
		if (t_token[i].c == *format)
		t_token[i].fonction(a);
		i++;
	}

}

int     ft_printf(const char *format, ...)
{
	//t_tab		*t_token;
	va_list		ap;
	t_env		env;

	env.ret = 0;
	env.t_token = (t_tab*)malloc(sizeof(t_tab*) * 2);
	//printf("format: %s\n",format);
	ft_init_list(&(env.t_token));
	va_start(ap, format);
	while(*format != '\0')
	{
		if (*format == '%')
			{
				if(format[1] == '%')
				{
					ft_putchar('%');
					format++;
				}
				else
				ft_check_token(++format, &ap, env.t_token);
			}
			else
			{
				ft_putchar(*format);
			}
			format++;
	}
	va_end(ap);
	return (0);
}

int main ()
{
	//printf("abc");
	printf("printf:|%4d|%2d|\n",123,123);
	ft_printf("ft_printf:|%5d|%2d|\n",123,123);
    ft_printf("|abc|%%|%d|%c|\n",0,'1');
    return (0);
}

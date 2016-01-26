/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:40:46 by djoly             #+#    #+#             */
/*   Updated: 2016/01/26 16:41:02 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void ft_check_token(const char *format, va_list *ap, t_t_list *t_token)
{
    void *a;
    a = va_arg(*ap, void *);
    while (t_token)
    {
        if (t_token->c == *format)
            t_token->fonction(a);
        t_token = t_token->next;
    }
    /*
    if (*format == 'd')
        ft_putnbr((int) a);
    else if (*format == 'c')
        ft_putchar((char) a);*/
}
int     ft_printf(const char *format, ...)
{
    t_t_list     *t_token;
    va_list     ap;
    //void    *ret;
    //int      ret;
    t_token = malloc(sizeof(t_t_list));
    ft_init_list(t_token);
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
                    ft_check_token(++format, &ap, t_token);
                }
                else
                ft_putchar(*format);
            format++;
        }
        return (0);

    /*ret = va_arg(ap, void* );
    printf("%d", (int) ret);
    ret = va_arg(ap, void *);
    printf("%c", (char) ret);*/
    va_end(ap);
    return (0);
}

int main ()
{
    ft_printf("str%%%d%cabc",0,'A');
    return (0);
}

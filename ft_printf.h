/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:33:26 by djoly             #+#    #+#             */
/*   Updated: 2016/01/29 16:50:58 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/includes/libft.h"
# define TOKEN "sSpdDioOuUxXcC"
# define FLAGS "#0-+ hljz."

# define FONCT env->fonct
# define FORMAT env->format
# define IFOR env->ifor
# define ITOK   env->itok
# define ARG    env->arg
# define AP     env->ap
# define NBR    env->nbr
# define NBRPREC	env->nbr_precision
# define FNDFLAGS  env->fndflags
# define RET    env->ret


/*
typedef struct          s_t_list
{
    char                c;
    void                (*fonction)(void *);
    struct s_t_list       *next;
}                       t_t_list;
*/
typedef struct s_env t_env;

typedef struct			s_tab
{
	char	c;
	int	(*fonction)(t_env *env);
}						t_tab;

typedef struct			s_env
{
	t_tab		*fonct;
	const char	*format;
    int         ifor;
    int         itok; // indice des token dans str et *fonct
    void        *arg;
    va_list     ap;
 //   int         token;
	int			nbr;
	int			nbr_precision;
    char        fndflags[10];//0# 10 2- 3+ 4  5h 6l 7j 8z 9.
	int			ret;
}						t_env;

// *tab de structure
void                    ft_init(t_tab *t_token);
t_tab                   *ft_init_list();
void					ft_init_env(t_env *env);
int                     ft_printf(const char *format,...);
void                    run_format(t_env *env);
int                    ft_check_token(t_env *env);
int                     ft_check_flags(t_env *env);
int                     ft_check_nbr(t_env *env);
void					ft_check_env(t_env *env);
int                     fonct_s(t_env *env);
int                     fonct_S(t_env *env);
int                     fonct_p(t_env *env);
int                     fonct_d(t_env *env);
int                     fonct_D(t_env *env);
int                     fonct_i(t_env *env);
int                     fonct_o(t_env *env);
int                     fonct_O(t_env *env);
int                     fonct_u(t_env *env);
int                     fonct_U(t_env *env);
int                     fonct_x(t_env *env);
int                     fonct_X(t_env *env);
int                     fonct_c(t_env *env);
int                     fonct_C(t_env *env);
char					*ft_strchr(const char *s, int c);
int						ft_putchar(char c);
int						ft_putnbr(int n);
int						ft_nbrlen(int nb);
void						ft_putstr(const char *str);
int						ft_atoi(const char *str);




#endif

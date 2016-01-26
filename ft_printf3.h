/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:33:26 by djoly             #+#    #+#             */
/*   Updated: 2016/01/26 20:19:26 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/includes/libft.h"
/*
typedef struct          s_t_list
{
    char                c;
    void                (*fonction)(void *);
    struct s_t_list       *next;
}                       t_t_list;
*/
typedef struct			s_tab
{
	char	c;
	void	(*fonction)(void *);
}						t_tab;

typedef struct			s_env
{
	int			ret;
	t_tab		*t_token;
	const char	*format;
}						t_env;

// *tab de structure
void                    ft_init(t_tab *t_token);
void                    ft_init_list(t_tab **t_token);

#endif

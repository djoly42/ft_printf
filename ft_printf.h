/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:42:18 by djoly             #+#    #+#             */
/*   Updated: 2016/01/26 20:17:25 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/includes/libft.h"
typedef struct          s_t_list
{
    char                c;
    void                (*fonction)(void *);
    struct s_t_list       *next;
}                       t_t_list;

void                    ft_init(t_t_list *t_token);
void                    ft_init_list(t_t_list *t_token);


// *tab de structure

#endif

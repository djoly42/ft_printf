
#include "ft_printf.h"

int     fonct_s(t_env *env)
{
    if (FNDFLAGS[9] == 1 && NBRPREC == -1)
            return (0);
    if (ARG == NULL)
    {
     RET = RET + ft_putstr("(null)");
     return (0);
    }
    ARGLEN = ft_strlen((char *)ARG);
    if (FNDFLAGS[2] == -1 && NBR > ARGLEN) //pas de - et nbr
    {
        if (NBRPREC != -1 && NBR > NBRPREC)
            RET = RET + ft_putspace(NBR - NBRPREC);
        else
            RET = RET + ft_putspace(NBR - ARGLEN);
    }
    if (FNDFLAGS[9] == 1 && NBRPREC != -1)
        RET = RET + ft_putstr2((char *)ARG, NBRPREC);
    else
        RET = RET + ft_putstr((char *)ARG);
    if (FNDFLAGS[2] == 1 && NBR > ARGLEN)
        RET = RET + ft_putspace(NBR - ARGLEN);
    return (0);
}

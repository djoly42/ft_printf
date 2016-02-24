
#include "ft_printf.h"


static void x_prec(t_env *env)
{
	if (FNDFLAGS[2] == -1 && NBR != -1 && NBRPREC != -1) //pas de - et nbr
	{
		if (NBRPREC > ARGLEN)
		{
		if (FNDFLAGS[1] == 1)
			RET = RET + ft_putzero2(NBR - ARGLEN);
		else
			RET = RET + ft_putspace(NBR - ARGLEN);
		}
		else
		{
		if (FNDFLAGS[1] == 1)
			RET = RET + ft_putzero2(NBR - NBRPREC);
		else
			RET = RET + ft_putspace(NBR - NBRPREC);
		}
	}
	if (FNDFLAGS[9] == 1 && NBRPREC != -1)
		RET = RET + ft_putstr2((char *)ARG, NBRPREC);
	else
		RET = RET + ft_putstr((char *)ARG);
	if (FNDFLAGS[2] == 1 && NBR != -1 && NBRPREC != -1)
	{
		if (NBRPREC > ARGLEN)
			RET = RET + ft_putspace(NBR - ARGLEN);
		else
			RET = RET + ft_putspace(NBR - NBRPREC);
	}
}

int     fonct_s(t_env *env)
{
    if (FNDFLAGS[9] == 1 && NBRPREC == -1)
		return (0);
	if (ARG == NULL)
    {
     RET += ft_putstr("(null)");
     return (0);
    }
    ARGLEN = ft_strlen((char *)ARG);
	if (FNDFLAGS[9] == 1)
		x_prec(env);
	else
	{
    if (FNDFLAGS[2] == -1 && NBR > ARGLEN) //pas de - et nbr
    {
        if (FNDFLAGS[1] == 1)
            RET = RET + ft_putzero2(NBR - ARGLEN);
        else
            RET = RET + ft_putspace(NBR - ARGLEN);
    }
    RET = RET + ft_putstr((char *)ARG);
    if (FNDFLAGS[2] == 1 && NBR > ARGLEN)
        RET = RET + ft_putspace(NBR - ARGLEN);
	}
	return (0);
}

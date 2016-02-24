
#include "ft_printf.h"
/*
static char					*ft_join_free(char *s1, char *s2)
{
	char				*tmp;

	tmp = s1;
	s1 = ft_strjoin(tmp, s2);
	free(tmp);
	return (s1);
}

static char *ft_strx(unsigned int nb ,char *str)
{
    if (nb != 0 )
        str = ft_join_free(HEXA[nb % 16], str);
    return (ft_strx(nb / 16, str));
}
*/
static int hexa_len(unsigned int nb)
{
    int i;

	if (nb == 0)
		return (1);
    i = 0;
    while (nb != 0)
    {
        i++;
        nb = nb / 16;
    }
    return (i);
}


static int print_hexa(unsigned int nb, t_env *env)
{
    int i;

    i = 0;
    if (nb != 0)
    {
        print_hexa(nb / 16, env);
        if (ITOK == 10)
            ft_putchar(HEXA[nb % 16]);
        else
            ft_putchar(HEXA2[nb % 16]);
        return (i);
    }
    return (i);
}

int                     fonct_x(t_env *env)
{
	env->arglen = hexa_len((unsigned int)ARG);
 //ft_putnbr(env->arglen);
 	if (FNDFLAGS[0] == 1 && NBR != -1)//#
     	NBR = NBR - 2;
    if (FNDFLAGS[2] != 1 && FNDFLAGS[9] == 1 && NBR != -1 &&  NBRPREC != -1 ) //.
    	RET = RET + ft_putspace(NBR - NBRPREC);
    else if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == -1 && NBR != -1) // pas de - et nbr pas de 0
    {

        RET = RET + ft_putspace(NBR - env->arglen);
    }
	if (FNDFLAGS[0] == 1)//#
	{
		RET = RET + ft_putzero2(1);
		RET = RET + ft_putchar('x');
	}
    if (NBRPREC != -1 && NBRPREC > env->arglen )//.
	    RET = RET + ft_putzero2(NBRPREC - env->arglen);
    if (FNDFLAGS[2] != 1 && FNDFLAGS[1] == 1 && NBR != -1)
	    RET = RET + ft_putzero2(NBR - env->arglen);

    if ((unsigned int)ARG == 0)
		ft_putchar('0');
	else
		print_hexa((unsigned int)ARG, env);
    RET = RET + ARGLEN;
   // ft_putnbr(RET);
    if (FNDFLAGS[2] == 1 && FNDFLAGS[9] == 1 && NBRPREC != -1 && NBR != -1)//.
	    RET = RET + ft_putspace(NBR - NBRPREC);
    else if (FNDFLAGS[2] == 1 && NBR != -1 && NBR > env->arglen && FNDFLAGS[9] == -1) // - et nbr
		{
        //if (FNDFLAGS[0] == 1)
        //    NBR = NBR - 2;
        RET = RET + ft_putspace(NBR - env->arglen);
        }
    //ft_putnbr(RET);
return (1);
}
/*
int     fonct_x(t_env *env)
{
//    char *str;

  //  str = (char*)malloc(sizeof(char*));
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
}*/

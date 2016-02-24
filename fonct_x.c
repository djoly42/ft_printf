
#include "ft_printf.h"

static int hexa_leni(unsigned int nb)
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

static int hexa_lenl(unsigned long int nb)
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

static int hexa_lenll(unsigned long long int nb)
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

static int hexa_len(t_env *env)
{
	if (FNDFLAGS[6] == 1)
		return (hexa_lenl((unsigned long int)ARG));
	else if (FNDFLAGS[6] == 2)
		return (hexa_lenll((unsigned long long int)ARG));
	else
		return (hexa_leni((unsigned int)ARG));
}

static void print_hexai(unsigned int nb, t_env *env)
{
	if (nb != 0)
	{
		print_hexai(nb / 16, env);
		if (ITOK == 10)
			ft_putchar(HEXA[nb % 16]);
		else
			ft_putchar(HEXA2[nb % 16]);
	}
}

static void print_hexal(unsigned long int nb, t_env *env)
{
	if (nb != 0)
	{
		print_hexal(nb / 16, env);
		if (ITOK == 10)
			ft_putchar(HEXA[nb % 16]);
		else
			ft_putchar(HEXA2[nb % 16]);
	}
}

static void print_hexall(long long unsigned int nb, t_env *env)
{
	if (nb != 0)
	{
		print_hexall(nb / 16, env);
		if (ITOK == 10)
			ft_putchar(HEXA[nb % 16]);
		else
			ft_putchar(HEXA2[nb % 16]);
	}
}

static void print_hexaj(uintmax_t nb, t_env *env)
{
	if (nb != 0)
	{
		print_hexall(nb / 16, env);
		if (ITOK == 10)
			ft_putchar(HEXA[nb % 16]);
		else
			ft_putchar(HEXA2[nb % 16]);
	}
}

static int print_hexa(t_env *env)
{

	if (FNDFLAGS[6] == 1)
		print_hexal((long long unsigned int)ARG, env);
	else if (FNDFLAGS[6] == 2)
		print_hexall((long long unsigned int)ARG, env);
	else if (FNDFLAGS[7] == 1)
		print_hexaj((uintmax_t)ARG, env);
	else
		print_hexai((unsigned int)ARG, env);
}


static int 	print_dies()
{
		ft_putzero2(1);
		ft_putchar('x');
		return (2);
}



static int ft_test0(t_env *env)
{
		if (FNDFLAGS[6] == 1 && (long long unsigned int)ARG == 0)
			return (1);
		else if (FNDFLAGS[6] == 2 && (long long unsigned int)ARG == 0)
			return (1);
		else if ((long unsigned int)ARG == 0)
			return (1);
		else if (FNDFLAGS[7] == 1 && (uintmax_t)ARG == 0)
			return (1);
		else if (FNDFLAGS[6] == -1 && (unsigned int)ARG == 0)
			return (1);
		else
			return (0);
}

static void x_prec(t_env *env)
{
	if (FNDFLAGS[2] != 1 && FNDFLAGS[9] == 1 && NBR != -1 &&  NBRPREC != -1 ) //.
		RET = RET + ft_putspace(NBR - NBRPREC);
		if (FNDFLAGS[0] == 1)//#
			RET = RET + print_dies();
	    if (NBRPREC != -1 && NBRPREC > env->arglen )//.
		    RET = RET + ft_putzero2(NBRPREC - env->arglen);

			if (ft_test0(env))
				ft_putchar('0');
			else
				print_hexa(env);
			RET = RET + ARGLEN;
			   // ft_putnbr(RET);
		    if (FNDFLAGS[2] == 1 && FNDFLAGS[9] == 1 && NBRPREC != -1 && NBR != -1)//.
			    RET = RET + ft_putspace(NBR - NBRPREC);

}

int                     fonct_x(t_env *env)
{
	env->arglen = hexa_len(env);
 //ft_putnbr(env->arglen);
	if (FNDFLAGS[9] == 1)
		x_prec(env);
	else
	{
 	if (FNDFLAGS[0] == 1 && NBR != -1)//#
     	NBR = NBR - 2;
     if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == -1 && NBR != -1) // pas de - et nbr pas de 0
        RET = RET + ft_putspace(NBR - env->arglen);
	if (FNDFLAGS[0] == 1)//#
		RET = RET + print_dies();
    if (NBRPREC != -1 && NBRPREC > env->arglen )//.
	    RET = RET + ft_putzero2(NBRPREC - env->arglen);
    if (FNDFLAGS[2] != 1 && FNDFLAGS[1] == 1 && NBR != -1)
	    RET = RET + ft_putzero2(NBR - env->arglen);

    if (ft_test0(env))
		ft_putchar('0');
	else
		print_hexa(env);
    RET = RET + ARGLEN;
   // ft_putnbr(RET);
     if (FNDFLAGS[2] == 1 && NBR != -1 && NBR > env->arglen && FNDFLAGS[9] == -1) // - et nbr
		{
        //if (FNDFLAGS[0] == 1)
        //    NBR = NBR - 2;
        RET = RET + ft_putspace(NBR - env->arglen);
        }
	}
    //ft_putnbr(RET);
return (1);
}
/*
int                     fonct_x(t_env *env)
{
	env->arglen = hexa_len((unsigned int)ARG);
 //ft_putnbr(env->arglen);
	if (FNDFLAGS[9] == 1)
		x_prec(env);
	else
	{
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
	}
    //ft_putnbr(RET);
return (1);
}*/


#include "ft_printf.h"
/*
static void	ft_putspace(t_env *env)
{
	int i;

ft_putstr(">>itok>>");
ft_putnbr(ITOK);
ft_putstr("<<");
ft_putstr(">>nbr>>");
ft_putnbr(NBR);
ft_putstr("<<");

    i = -1;
	NBR = NBR - ft_nbrlen((int)ARG);

    ft_putstr(">>nbr>>");
    ft_putnbr(NBR);
    ft_putstr("<<");

    if (FNDFLAGS[3] == 1 && (int)ARG > 0) //+ et arg+
		NBR = NBR - 1;
    ft_putstr(">>nbr>>");
    ft_putnbr(NBR);
    ft_putstr("<<");



	while (++i < (NBR))
		 RET = RET + ft_putchar(' ');


}*/

static void	ft_putzero(t_env *env)
{
	int i;

    if ((int)ARG < 0 && env->putneg != 1)
    {
        RET = RET + ft_putchar('-');
        //ARG = (-1) * (int)env->arg;
        //if (NBR != -1)
        //    NBR = NBR - 1;
        env->putneg = 1;
    }
	if (NBR != -1)// && FNDFLAGS[2] != 1)
        NBR = NBR - ft_nbrlen((int)ARG);
		//else
		//NBR = NBR - ft_nbrlen((int)ARG);
	i = -1;

	ft_putstr(">>nbr>>");
	ft_putnbr(NBR);
	ft_putstr("<<");

	while (++i < (NBR))
	 RET = RET + ft_putchar('0');


}
static void ft_flag_prec(t_env *env)
{
	/*
	ft_putstr(">>nbr>>");
	ft_putnbr(NBR);
	ft_putstr("<<");
	ft_putstr(">>nbrprec>>");
	ft_putnbr(NBRPREC);
	ft_putstr("<<");
	*/
	if (NBRPREC != -1)
		RET = RET + ft_putspace(NBR - NBRPREC);
	if (NBR == -1)
		NBR = NBRPREC;
	else
		NBR =  NBRPREC;

		ft_putstr(">>nbr>>");
		ft_putnbr(NBR);
		ft_putstr("<<");

	ft_putzero(env);

}
static void	ft_check_env(t_env *env)
{
/*	 ft_putstr(">>NBRLEN>>");
	   ft_putnbr(ft_nbrlen((int)ARG));
	   ft_putstr("<<");
*/
	if (FNDFLAGS[9] == 1)
		ft_flag_prec(env);
	else
	{
    if ( (FNDFLAGS[4] == 1 && NBR == -1)) // ' ' pas de NBR
        if ((int)ARG > 0)
            RET = RET + ft_putchar(' ');
	if (NBR != -1 && NBR > ft_nbrlen((int)ARG))// && ITOK == 12)
	{
       if ((FNDFLAGS[3] == 1) &&  ((int)ARG > 0)) // + et ARG >0
          NBR = NBR - 1;
        if (FNDFLAGS[1] == 1 && FNDFLAGS[2] != 1) //0
			ft_putzero(env);
		else
		    RET = RET + ft_putspace((NBR = NBR - ft_nbrlen((int)ARG)));
	}
	}
	//if (NBR != -1 && FNDFLAGS[2] == 1 && ITOK == 12)

}

int     fonct_d(t_env *env)
{

	int	pos;
    //    ft_putstr(">>1IF<<");
    if(FNDFLAGS[2] != 1) // pas de -
	    ft_check_env(env);
	if ((FNDFLAGS[3] == 1) && ((int)ARG > 0)) //(FNDFLAGS[2] != 1))// + et pas de -ARG || ((int)ARG > 0)))
    {
//        ft_putstr(">>1IF<<");
 /*  ft_putstr(">>RET>>");
    ft_putnbr(RET);
    ft_putstr("<<");
*/
       // if (NBR != -1)
         //   NBR = NBR - 1;
        RET = RET + ft_putchar('+');
/*     ft_putstr(">>RET>>");
    ft_putnbr(RET);
    ft_putstr("<<");
*/
    }
       /* if (FNDFLAGS[2] == 1)
        {
        //ft_putstr(">>2IF<<");
		    RET = RET +ft_putchar('-');
        }*/
    //ft_putstr(">>RET>>");
    //ft_putnbr(RET);
    //ft_putstr("<<");

	if (FNDFLAGS[5] == -1 && FNDFLAGS[6] == -1 && (int)ARG < 0)//          (long long int)ARG < 9223372036854775808)//  (long long int)ARG < 0 )//&& FNDFLAGS[2] != 1) // - nest pas encore ecrie, voir putzero
	{
		//ft_putstr(">>DANS IF1>>");
		pos = (-1) * (int)ARG;
		if (env->putneg != 1)
		{
			RET = RET + ft_putchar('-');
			env->putneg = 1;
		}
		RET = RET + ft_putnbr(pos);
	}
	else if(FNDFLAGS[6] == 1)
	{
		//ft_putstr(">>DANS IF2>>");
		RET = RET + ft_putnbr((long int)ARG);
	}
	else if(FNDFLAGS[6] == 2)
	{
		//ft_putstr(">>DANS IF3>>");
		RET = RET + ft_putnbr((long long int)ARG);
	}
	else if(FNDFLAGS[5] == 1)
	{
		//ft_putstr(">>DANS IF4>>");
		RET = RET + ft_putnbr((short int)ARG);
	}
	else if(FNDFLAGS[5] == 2)
	{
		//ft_putstr(">>DANS IF5>>");
		RET = RET + ft_putnbr((signed char)ARG);
	}
	else
	{
		//ft_putstr(">>DANS ELSE>>");
    	RET = RET + ft_putnbr((int)ARG);
	}
    /*
    ft_putstr(">>RET>>");
    ft_putnbr(RET);
    ft_putstr("<<");
*/

    if(FNDFLAGS[2] == 1) //-
	    ft_check_env(env);

return (1);
}

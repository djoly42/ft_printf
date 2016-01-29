
#include "ft_printf.h"

int     fonct_c(t_env *env)
{
	if (FNDFLAGS[2] == 1)
	{
		//ft_check_env(env);
		RET = RET + ft_putchar((char)ARG);
		ft_check_env(env);
	}
	else
	{
		ft_check_env(env);
		RET = RET + ft_putchar((char)ARG);
	}
    return(0);
}

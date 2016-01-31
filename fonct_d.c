
#include "ft_printf.h"

int     fonct_d(t_env *env)
{
	ft_check_env(env);
	if (FNDFLAGS[3] == 1)
		RET = RET + ft_putchar('+');
	RET = RET + ft_putnbr(ARG);

return (1);
}

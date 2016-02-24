
#include "ft_printf.h"

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

int     fonct_x(t_env *env)
{
    char *str;
        
    str = (char*)malloc(sizeof(char*));
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

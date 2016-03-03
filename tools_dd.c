int		ft_nbrlenD(long int nb)
{
	int i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

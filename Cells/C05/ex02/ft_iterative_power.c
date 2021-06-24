int	ft_iterative_power (int nb, int power)
{
	int	counter;
	int	i;

	i = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	counter = power;
	while (counter > 0)
	{
		i *= nb;
		counter -= 1;
	}
	return (i);
}

int	ft_iterative_factorial(int nb)
{
	int	tmp;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	tmp = (nb - 1);
	while (tmp >= 0)
	{
		nb *= tmp;
		tmp -= 1;
	}
	return (nb);
}

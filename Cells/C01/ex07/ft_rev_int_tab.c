void	ft_rev_int_tab(int *tab, int size)
{	
	int	tempval;
	int	count;

	count = 0;
	while ((size / 2) > 1)
	{
		tempval = tab[count];
		tab[count] = tab[size - 1];
		tab[size - 1] = tempval;
		size--;
		count++;
	}
}

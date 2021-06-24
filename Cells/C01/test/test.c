

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

int	main(void)
{
	int size = 5;
	int count = 0;
	int count2 = 0;
	
	int	tab[5];
	tab[0] = 4;
	tab[1] = 5;
	tab[2] = 6;
	tab[3] = 7;
	tab[4] = 8;
	while (count < size)
	{
		printf("%c", (tab[count] + '0'));
		count++;
	}
	ft_rev_int_tab(tab, size);
	while (count2 < size)
	{
		printf("%c", (tab[count2] + '0'));
		count2++;
	}
}

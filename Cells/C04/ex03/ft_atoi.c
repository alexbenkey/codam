int	add_int_from_string(char *str, int i);

int	ft_atoi(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	i = add_int_from_string(str, i);
	return (i *= n);
}

int	add_int_from_string(char *str, int i)
{
	int	element;
	int	newint;

	newint = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		element = (str[i] - '0');
		newint *= 10;
		newint += element;
		i++;
	}
	return (newint);
}

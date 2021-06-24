void	ft_strlen(char *str)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	while (str[index] != '\0')
	{
		index++;
		count++;
	}
	return (count);
}
ex00
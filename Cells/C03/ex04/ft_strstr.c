char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] == to_find[j])
		{
			i++;
			j++;
			if (to_find[j] == '\0' && k == 0)
				k = i - j;
		}
		i++;
		j = 0;
	}
	i = 0;
	return (&str[k]);
}

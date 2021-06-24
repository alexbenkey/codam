int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;

	if (n == 0)
		return (0); 
	count = 0;
	while (s1[count] && (count < (n - 1)))
	{
		if (s1[count] != s2[count])
		{
			return (((unsigned char)s1[count]) - ((unsigned char)s2[count]));
		}
		count++;
	}	
	if (s1[count] != s2[count])
		return ((unsigned char)s1[count] - (unsigned char)s2[count]);
	else
		return (0);
}


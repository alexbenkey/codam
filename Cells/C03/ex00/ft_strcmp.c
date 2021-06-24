int	ft_strcmp(char *s1, char *s2)
{
	int	count;

	count = 0;
	while ((s1[count] != '\0' ) && (s2[count] != '\0'))
	{
		if (s1[count] != s2[count])
		{
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		}
		count++;
	}	
	if (s1[count] != s2[count])
		return ((unsigned char)s1[count] - (unsigned char)s2[count]);
	else
		return (0);
}

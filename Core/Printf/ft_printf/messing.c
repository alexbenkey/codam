#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	test_strlcpy(char *dest, char *src, int len)
{
	int	i;

	dest = (char *)malloc(sizeof(len));
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] != 0 && i < (dstsize - 1))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	while (*(src + i) != 0)
		i++;
	return (i);
}

int	printhex(long long n, char c, int i)
{
	char	vals[17];
	int		current;

	if (c == 'X')
		ft_strlcpy(vals, "0123456789ABCDEF", 17);
	if (c == 'x')
		ft_strlcpy(vals, "0123456789abcdef", 17);
	if (n < 0)
		n = (2147483647 + (2147483649 - (n * -1)));
	if (n > 0)
	{
		i++;
		current = n % 16;
		i = printhex((n / 16), c, i);
		write (1, &vals[current], 1);
	}
	if (n == 0 && i == 0)
	{
		write (1, &vals[n], 1);
		i++;
	}
	return (i);
}

int	test_printhex(unsigned long long n, int i)
{
	char	*vals;

	ft_strlcpy(vals, "0123456789abcdef", 17);
	if (n > 0)
	{
		i++;
		test_printhex((n / 16), i);
		write(1, &vals[n % 16], 1);
	}
	if (n == 0 && i == 0)
	{
		write (1, &vals[n], 1);
		i++;
	}
	return (i);
}

int	main(void)
{
	//printf("test: %d", test_printhex(12345, 0));
 	printhex(12345, 'c', 0);
}

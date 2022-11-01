#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int	ft_atoi(const char *str);
static int	p_check(const char *str);

int main(int argc, char **argv)

{

	setlocale(LC_CTYPE, "");

	wchar_t star1 = argv[1][0];

	wchar_t star2 = 0x2605;

	wprintf(L"input: %lc\n",star1);

	wprintf(L"White Star: %lc\n",star2);

}


static int	p_check(const char *str);

int	ft_atoi(const char *str)
{
	int	i;
	int	p;
	int	val;

	i = 0;
	val = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	p = p_check(str);
	if (*str == '-' || *str == '+')
		str++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		val *= 10;
		val += (str[i] - 48);
		i++;
		if (i == 19 && str[i] && p == -1)
			return (0);
		else if (i == 19 && str[i])
			return (-1);
	}
	return (val * p);
}

static int	p_check(const char *str)
{
	int	i;
	int	p;

	p = 1;
	i = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			p *= -1;
		str++;
	}
	return (p);
}

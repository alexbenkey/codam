#include <stdio.h>

/* 
	Simple tool for calculating the remaining time to be spent in the codam building. 
	To use compile monitoring.c and run the executable followed by the logtimes of previous days in the current week.
	format times as hh:mm and seperate by space.   
*/

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

int	get_hours(char *time)
{
	int		i;
	char	hrs[5];

	i = 0;
	while (time[i] && time[i] != ':')
	{
		hrs[i] = time[i];
		i++;
	}
	return (ft_atoi(hrs));
}

int	get_mins(char *time)
{
	int		i;
	int		j;
	char	mins[5];

	i = 0;
	j = 0;
	while (time[i])
	{	
		while (time[i] != ':')
			i++;
		i++;
		while (time[i])
		{
			mins[j] = time[i];
			i++;
			j++;
		}
	}
	return (ft_atoi(mins));
}

int	main(int argc, char **argv)
{
	int	i;
	int	hours;
	int	mins;

	hours = 0;
	mins = 0;
	i = 1;
	while (i < argc)
	{
		hours += get_hours(argv[i]);
		mins += get_mins(argv[i]);
		i++;
	}
	if (mins > 60)
	{
		hours += (mins / 60);
		mins = (mins % 60);
	}
	printf("total time: %i hours %i mins", hours, mins);
	if (mins)
	{
		mins = (60 - mins);
		hours += 1;
		hours = 24 - hours;
		printf("\n%i hours and %i mins to go", hours, mins);
	}
	else
	{
		hours = 24 - hours;
		printf("\n%i hours to go", hours);
	}
}

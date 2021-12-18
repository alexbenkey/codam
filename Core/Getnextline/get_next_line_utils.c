#include "get_next_line.h"

void	ft_putstr(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
}
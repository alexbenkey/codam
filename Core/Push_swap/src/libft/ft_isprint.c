#include "libft.h"

int	ft_isprint(unsigned int input)
{
	if (input >= 32 && input <= 126)
		return (1);
	else
		return (0);
}

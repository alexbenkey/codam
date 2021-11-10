#include "libft.h"

int	ft_tolower(int input)
{	
	if (input >= 65 && input <= 90)
		return (input + 32);
	else
		return (input);
}

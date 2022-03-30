#include "libft.h"

int	ft_toupper(int input)
{	
	if (input >= 97 && input <= 122)
		return (input - 32);
	else
		return (input);
}

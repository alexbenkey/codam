#include "libft.h"

int	ft_isalpha(int input)
{
	return ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'));
}

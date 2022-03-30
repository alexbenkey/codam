#include "libft.h"

int	ft_isalnum(int input)
{
	return (ft_isalpha(input) || ft_isdigit(input));
}

#include "ft_printf.h"

size_t	ft_strlen(const char *string)
{
	size_t	index;

	index = 0;
	if (!string)
		return (0);
	while (string[index] != 0)
		index++;
	return (index);
}

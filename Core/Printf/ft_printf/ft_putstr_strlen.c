#include "ft_printf.h"

int	ft_putstr_strlen(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	if (!s)
	{
		ft_putstr_strlen("(null)");
		return (6);
	}
	return (ft_strlen(s));
}

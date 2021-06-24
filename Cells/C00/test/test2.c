#include <unistd.h>
void	ft_putchar(char c);

int main(void)
{
	int	nb;
	nb = 105;

	ft_putchar((char)(nb % 10 + '0'));	
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


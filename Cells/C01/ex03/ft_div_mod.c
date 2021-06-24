void	ft_div_mod(int a, int b, int *div, int *mod)
{	
	int	c;

	*div = (a / b);
	c = (a % b);
	*mod = c;
}

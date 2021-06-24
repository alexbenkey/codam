int	ft_fibonacci (int index)
{
	if (index == 0 || index == 1)
		return (index);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci (index - 2));
}

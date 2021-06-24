#include<stdio.h>
#include<string.h>
#include <unistd.h>


char * ft_strncpy(char *dest, char *src, unsigned int n);

// int main(void)
// {
// 	int a = 9;

// 	char src[] =  "\200";
// 	char dest[] = "\0";

// 	ft_strncpy(dest, src, a);
// 	strncpy(dest, src, a);
// 	printf("%s \n%s", dest, src); 
// 	return 0;
// }


#include<stdio.h>
#include<string.h>
#include <unistd.h>



int main(void)
{
printf("\n\n\n\n EX01 || input length = 10, source1 = test \n\n");
	char	*source1;
	char	ft_dest1[15] = "111111111111111";
	char	*ft_test_ret1;
	char	dest1[15] = "111111111111111";
	char	*test_ret1;
	int		length1;

	length1 = 10;
	source1 = "test";
	ft_test_ret1 = ft_strncpy(ft_dest1, source1, length1);
	test_ret1 = strncpy(dest1, source1, length1);
	printf("strncpy: %s\n", dest1);
	printf("ft_strncpy: %s\n", ft_dest1);
	printf("strcmp %d\n", strcmp(test_ret1, ft_test_ret1));
	printf("As numbers, i < length:\n");
	for(int i=0; i<length1; i++)
	{
		printf("test_ret[%d]: %d && ", i, test_ret1[i]);
		printf("ft_test_ret[%d]: %d\n", i, ft_test_ret1[i]);
	}
}

#include<stdio.h>

// Ex00
char *ft_strcpy(char *dest, char *src);

int main() 
{
   char str1[20] = "C p";
   char str2[20] = "jello";

	;
	printf("%s ", ft_strcpy(str2, str1));

   return 0;
}

// //ex01

// #include<stdio.h>

// char * ft_strncpy(char *dest, char *src, unsigned int n);

// int main(void)
// {
// 	int a = 9;

// 	char src[] =  "src";
// 	char dest[] = "Destination";

// 	ft_strncpy(dest, src, a);

// 	printf("%s \n%s", dest, src);
// 	return 0;
// }


// //ex02
// #include<stdio.h>

// int	ft_str_is_alpha(char *str);

// int main(void)
// {
// 	int a;
// 	char str[] = "";
// 	a = ft_str_is_alpha(str); 
// 	printf("%d", a);
// }

// //ex03
// #include<stdio.h>

// int	ft_str_is_numeric(char *str);

// int	main(void)
// {
// 	int a;
// 	char str[] = "";
// 	a = ft_str_is_numeric(str);
// 	printf("%d", a);
// }

// //ex04
// #include<stdio.h>

// int	ft_str_is_lowercase(char *str);

// int	main(void)
// {
// 	int a;
// 	char str[] = "asdAASFhuasf";
// 	a = ft_str_is_lowercase(str);
// 	printf("%d", a);
// }


// //ex05
// #include<stdio.h>

// int	ft_str_is_uppercase(char *str);

// int	main(void)
// {
// 	int a;
// 	char str[] = "ADASFAEF";
// 	a = ft_str_is_uppercase(str);
// 	printf("%d", a);
// }

// //ex06
// #include<stdio.h>

// int	ft_str_is_printable(char *str);

// int	main(void)
// {
// 	int a;
// 	char str[] = "asdqe";
// 	a = ft_str_is_printable(str);
// 	printf("%d", a);
// }

// //ex07

// #include<stdio.h>

// int	ft_strupcase(char *str);

// int	main(void)
// {
// 	int a;
// 	char str[] = "124asdqe1525?';[]";
// 	a = ft_strupcase(str);
// 	int count = 0;
// 	while (str[count])
// 	{
// 		printf("%c", str[count]);
// 		count++;
// 	}
// }

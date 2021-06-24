#include<stdio.h>

char *ft_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (0);
}


int main() 
{
   char str1[20] = "C p";
   char str2[20] = "jello";

	ft_strcpy(str2, str1);

	printf("%s \n%s", str2, str1);

   return 0;
}


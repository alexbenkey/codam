#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *ft_strncat(char *dest, char *src, unsigned int nb);

int main()
{
    char src_str[40] = "o";
    char dest_str[40] = "Hello world";
    int a;

    a = 100;
	printf("%s\n", ft_strncat(dest_str, src_str, a));
}
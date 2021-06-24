#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strstr(char *str, char *to_find);

int main()
{
    char src_str[40] = "o";
    char dest_str[40] = "Hello world";
    int a;

    a = 100;
   printf("%s\n", ft_strncat(dest_str, src_str, a));

    printf("%s", ft_strstr(dest_str, src_str));

}
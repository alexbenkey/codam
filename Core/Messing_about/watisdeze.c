#include <stdio.h>
#include <unistd.h>

int main(void)
{	
	char *emoji = {-16, -97, -92, -111};

	printf("what is dis? : %s", emoji);
	//write(1, emoji, 4);
	return (0);
}


#include <stdio.h>
#define PLAT "/bin/uname -a"

int main()
{
	printf("plat = %s\n", PLAT);
	return 0;
}

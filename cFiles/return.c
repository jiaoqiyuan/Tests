#include <stdio.h>

char *get_plat()
{
	char plat[32] = {0};
	snprintf(plat, sizeof(plat), "hello, world!");
	return plat;
}

int main()
{
	char *plat = NULL;
	plat = get_plat();
	printf("plat = %s\n", plat);
}

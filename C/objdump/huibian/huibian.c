#include <stdio.h>

void decode1(long *xp, long *yp, long *zp)
{
	long x = *xp;
	long y = *yp;
	long z = *zp;

	*xp = y;
	*yp = z;
	*zp = x;
}
int main()
{
	long x = 5;
	long y = 7;
	long z = 9;
	decode1(&x, &y, &z);
	printf("x = %ld\ty = %ld\tz = %ld\n", x, y, z);
}

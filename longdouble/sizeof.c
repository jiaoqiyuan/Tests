#include <stdio.h>

int main()
{
	long double ld;
	printf("sizeof long double = %ld\n", sizeof(ld));
	printf("sizeof char = %ld\n", sizeof(char));
	printf("sizeof long = %ld\n", sizeof(long));
	printf("sizeof double = %ld\n", sizeof(double));
	printf("sizeof float = %ld\n", sizeof(float));
	printf("sizeof char * = %ld\n", sizeof(char *));

	return 0;
}


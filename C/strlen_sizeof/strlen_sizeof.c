#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char str[10] = {0};
	printf("sizeof str[10] = %d\n", sizeof(str));
	printf("strlen str[10] = %d\n", strlen(str));

	snprintf(str, sizeof(str), "hello");
	printf("sizeof str[10] = %d\n", sizeof(str));
	printf("strlen str[10] = %d\n", strlen(str));

	
}

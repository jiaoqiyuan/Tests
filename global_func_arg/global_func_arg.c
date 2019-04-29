#include<stdio.h>

char name[32] = {0};

void set_name()
{
	sprintf(name, "hello");
}

int main()
{
	set_name(name);
	printf("name = %s\n", name);

	return 0;
}

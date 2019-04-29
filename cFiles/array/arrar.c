#include <stdio.h>

int main()
{
	char x[3];
	//123是assic码，打印时会自动转换成响应的字符
	x[0] = 200;
	x[1] = 124;
	x[2] = 125;

	printf("x[1] = %c\n", x[1]);
}

#include <stdio.h>
#include <string.h>

//buf作为参数传递仅函数后会被复制一份，函数内使用的buf就是复制的buf,所以对其操作不影响原buf指向的地址
int func_read(char *buf)
{
	sprintf(buf, "hello ");
	buf += strlen("hello ");
	sprintf(buf, "world!");
	return 0;
}

int main()
{
	char buf[256] = {0};
	
	func_read(buf);
	printf("buf = %s\n", buf);

	return 0;
}

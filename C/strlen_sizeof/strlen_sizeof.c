#include <stdio.h>
#include <string.h>

/* 用于测试sizeof和strlen返回的结果
 * sizeof用于计算数组分配的空间
 * strlen用于计算数组占用的空间（不包含 '\n' 占用的空间）
 */

int main(int argc, char* argv[]) {
	char str[10] = {0};
	printf("sizeof str[10] = %d\n", sizeof(str));
	printf("strlen str[10] = %d\n", strlen(str));

	snprintf(str, sizeof(str), "hello");
	printf("sizeof str[10] = %d\n", sizeof(str));
	printf("strlen str[10] = %d\n", strlen(str));

	
}

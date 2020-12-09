#include <stdio.h>


void test_array_index() {
	int i = 0;
	int arr[3] = {0};
	for(; i<=3; i++){
		arr[i] = 0;
		printf("hello world\n");
	}
}

/* 数组下标可以为负数 */
void test2() {
    double a1[4] = {1.2, 2.4, 3.6, 4.8};
    a1[-1] = 20.5;
    printf("a1[-1] = %f, addr = %p\n", a1[-1], &a1[-1]);
    printf("al addr = %p\n", a1);
}

int main(int argc, char* argv[]){
    //test_array_index();
    test2();
	return 0;
}


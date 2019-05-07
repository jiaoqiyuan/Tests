#include<stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("useage: ./ifFileExiste file-realpath");
		return -1;
	}
	if (!access(argv[1], 0)) {
		printf("file existe.\n");
	} else {
		printf("file not existe.\n");
	}

	return 0;
}

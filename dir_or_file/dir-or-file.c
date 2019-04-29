#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	if(argc != 2) {
		printf("useage: ./dir-or-file file-realpath\n");
		return -1;
	}
	char filepath[128] = {0};
	snprintf(filepath, sizeof(filepath), "%s", argv[1]);
	struct stat s;
	stat(filepath, &s);
	if(S_ISDIR(s.st_mode) && !S_ISREG(s.st_mode)) {
		printf("%s is dir.\n", filepath);
	} else if (!S_ISDIR(s.st_mode) && S_ISREG(s.st_mode)){
		printf("%s is file.\n", filepath);
		long lSize;
		FILE *pFile = NULL;
		pFile = fopen(filepath, "rb");
		if (pFile == NULL) {
			printf("fopen error.\n");
			return -1;
		}
		fseek(pFile, 0, SEEK_END);
		lSize = ftell(pFile);
		printf("filesize = %ld\n", lSize);
		if (lSize / 1024 < 1) {
			printf("filesize = %ldBytes\n", lSize);
		} else if ((lSize / 1024 >= 1) && (lSize/ 1024 / 1024) < 1) {
			printf("filesize = %5.2fKB\n", (float)lSize / 1024 );
		} else if ((lSize/1024/1024 > 1) && (lSize/1024/1024/1024) < 1) {
			printf("filesize = %5.2fMB\n", (float)lSize / 1024 /1024);
		} else if ((lSize/1024/1024/1024 > 1) && (lSize/1024/1024/1024/1024) < 1) {
			printf("filesize = %5.2fGB\n", (float)lSize / 1024 /1024/1024);
		}
	} else {
		printf("%s is not exitst.\n", filepath);
	}
	return 0;
}

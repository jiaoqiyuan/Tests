#include <stdio.h>
#include <string.h>

void remove_char(char *log, char ch)
{
	//去掉log中的双引号
	int i, j;
	for (i = j =0; log[i] != '\0'; i ++) {
		if (log[i] != ch) {
			log[j++] = log[i];
		}
	}

	log[j] = '\0';

}

int main()
{
	char log[512] = {0};
	char cmd[64] = {0};
	char filename[64] = {0};
	snprintf(filename, sizeof(filename), "log.data");
	snprintf(cmd, sizeof(cmd), "`which cat` %s | tail -n 10", filename);
	printf("cmd = %s\n", cmd);
	
	FILE *fd = popen(cmd, "r");
	if(fd == NULL) {
		printf("popen error!\n");
		return -1;
	} else {
		char value[512] = {0};
		while(fgets(value, sizeof(value), fd)) {
			value[strlen(value) - 1] = '\0';
			strcat(log, value);
		}
	}
	printf("log = %s\n", log);
	remove_char(log, '"');
	print("log = %s\n", log);

}

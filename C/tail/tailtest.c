#include <stdio.h>

int printaudit_loop_flag = 1;
int print_audit_flag = 1;

int main()
{
	int is_first_tail = 1;
	char cmd[64] = {0};
	snprintf(cmd, sizeof(cmd), "`which tail` -f tmp.cods");
	printf("cmd = %s\n", cmd);
	FILE *fd = popen(cmd, "r");
	if (fd == NULL) {
		printf("get print content popen error.");
		return (-1);
	}
	char value[512] = {0};
	if (fd != NULL) {
		while(printaudit_loop_flag){
			printf("testing...\n");
			if(is_first_tail) {
				is_first_tail = 0;
				while(fgets(value, sizeof(value), fd)) {
					printf("no use.\n");
				}
				sleep(5);
				continue;
			}

			if(print_audit_flag == 0) {
				sleep(5);
				continue;
			}

			if(fgets(value, sizeof(value), fd)){
				printf("value = %s\n", value);
			}
			sleep(5);
		}
	}
	fclose(fd);

}

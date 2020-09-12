#include <stdlib.h>
#include <stdio.h>

void exchange_point(char **p1, char **p2) {
	if (*p2) {
		free(*p2);
		*p2 = NULL;
	}
	*p2 = *p1;
	*p1 = NULL;
}

int main() {
	char *p1 = (char *)malloc(10);
	char *p2 = NULL;
	exchange_point(&p1, &p2);
	return 0;
}

#include <stdio.h>
#include <regex.h>

int main(int argc, char *argv[]) {
	printf("password = %s\n", argv[1]);
	//匹配邮件地址字符串
	const char *pattern = "^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*.\\w+([-.]\\w+)*$";
	char *password = argv[1];
	regmatch_t pmatch[1];
	regex_t reg;
	int cflags = REG_EXTENDED;
	int status;
	const size_t nmatch = 1;
	regcomp(&reg, pattern, cflags);
	status = regexec(&reg, password, nmatch, pmatch, 0);
	if (status == REG_NOMATCH) {
		printf("No match\n");
	} else if (0 == status) {
		printf("Match success: ");
		for (int i = pmatch[0].rm_so; i < pmatch[0].rm_eo; i++) {
			putchar(password[i]);
		}
		printf("\n");
	}
	regfree(&reg);
	return 0;
}

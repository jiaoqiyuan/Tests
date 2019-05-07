#include <stdio.h>
#include <string.h>

int main()
{
	char *str = "login|登录|<Object class=\"时间\" name=\"2018-07-02 11:15:48\"><登录用户>wst</登录用户><登录点>远程(192.168.8.167)</登录点><登录时间>2018-07-02 11:15:48</登录时间><登出时间/><状态>登录</状态></Object>|<Reason/>|2|审计|成功";
	if(strstr(str, "login")) {
		printf("find login\n");
		str = str + strlen("login") + 1;
		printf("str = %s\n", str);
		char action[16] = {0};
		char object[512] = {0};
		char reason[16] = {0};
		char level[2] = {0};
		char handle[8] = {0};
		char result[8] = {0};
		
		snprintf(action, strstr(str, "|") - str + 1, "%s", str);
		printf("action = %s\tlength = %ld\n", action, strstr(str, "|") - str + 1);
		str = strstr(str, "|") + 1;

		printf("str(object) = %s\n", str);
		snprintf(object, strstr(str, "|") - str + 1, "%s", str);
		printf("object = %s\tlength = %ld\n", object, strstr(str, "|") - str + 1);
		str = strstr(str, "|") + 1;

		printf("str(reason) = %s\n", str);
		snprintf(reason, strstr(str, "|") - str + 1, "%s", str);
		printf("reason = %s\tlength = %ld\n", reason, strstr(str, "|") - str + 1);
		str = strstr(str, "|") + 1;

		printf("str(level) = %s\n", str);
                snprintf(level, strstr(str, "|") - str + 1, "%s", str);
                printf("level = %s\tlength = %ld\n", level, strstr(str, "|") - str + 1);
                str = strstr(str, "|") + 1;
	
		printf("str(handle) = %s\n", str);
                snprintf(handle, strstr(str, "|") - str + 1, "%s", str);
                printf("handle = %s\tlength = %ld\n", handle, strstr(str, "|") - str + 1);
                str = strstr(str, "|") + 1;
	
		printf("str(result) = %s\n", str);
                snprintf(result, sizeof(result), "%s", str);
                printf("result = %s\tlength = %ld\n", result, strlen(result));
                str = strstr(str, "|") + 1;

		
	}
}

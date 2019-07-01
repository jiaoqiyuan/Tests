#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
	FILE *fp = NULL;
	int ret = 0;
	char buf[512] = {0};
	char cmd[512] = {0};
	//获取屏幕分辨率
	fp = popen("xrandr --current | head -n 1 | awk -F ',' '{print $2}' | awk '{print $2 \"x\" $4}'", "r");
	if (fgets(buf, sizeof(buf), fp)) {
		buf[strlen(buf)-1] = '\0';
		printf("buf = %s\n", buf);
	}
	fclose(fp);

	snprintf(cmd, sizeof(cmd), "ffmpeg -f x11grab -framerate 10 -s %s -i :0.0 -qscale 1 a.mp4 -y > /dev/null 2>&1", buf);
	printf("cmd = %s\n", cmd);
	fp = popen(cmd, "w");
	sleep(5);
	fprintf(fp, "q");
	fclose(fp);
	return 0;
}

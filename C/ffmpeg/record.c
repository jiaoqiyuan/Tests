#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void use_ffmpeg(){
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

	//snprintf(cmd, sizeof(cmd), "ffmpeg -f x11grab -framerate 10 -s %s -i :0.0 -qscale 1 a.mp4 -y > /dev/null 2>&1", buf);
	snprintf(cmd, sizeof(cmd), "./ffmpeg -f x11grab -s %s -r 5 -t 60 -i :0.0 -qscale 1 out.mp4 -y > /dev/null 2>&1", buf);
	printf("cmd = %s\n", cmd);
	fp = popen(cmd, "w");
	fclose(fp);
	snprintf(cmd, sizeof(cmd), "./ffmpeg -i out.mp4 -b 300k out300.mp4 -y");
	printf("cmd = %s\n", cmd);
	fp = popen(cmd, "r");
	fclose(fp);
}

//先截屏，再使用ffmpeg将多个截图转化成视频
void use_image(){
	FILE *fp = NULL;
	int ret = 0;
	char result[512] = {0};
	for(int i = 1; i <= 50; i++) {
		char cmd[256] = {0};
		snprintf(cmd, sizeof(cmd), "import -window root tmp/%d.jpg", i);
		usleep(100000);
		system(cmd);
	}
	system("./ffmpeg -f image2 -r 5 -i tmp/%d.jpg -vcodec mpeg4 -b 512k test.mp4 -y");
}

int main(int argc, char* argv[]) {
	//use_image();
	use_ffmpeg();
	return 0;
}

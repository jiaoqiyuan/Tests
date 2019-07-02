# 使用ffmpeg实现录屏功能demo

录屏命令：

```
ffmpeg -f x11grab -framerate 10 -s 3840x2160 -i :0.0 -qscale 1 a.mp4 -y > /dev/null 2>&1
ffmpeg -f x11grab -s 1920x1080 -r 10 -i :0.0 -qscale 1 out.mp4
```

使用popen运行命令，然后往打开的对应文件描述符中传入'q'以结束录制。

截屏命令：

```
import -window root test.jpg
```

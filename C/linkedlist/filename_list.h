#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//存放限制安装文件名的结构体
typedef struct filenames {
	char *filename;
	struct filenames *next;
} Filenames;

//创建list
Filenames *create_filelist();
//插入数据到list
void insert_to_filelist(Filenames *head, char *filename, int len);
//清空list
Filenames *clear_filelist(Filenames *head);
//检查是否包含指定的文件名
int if_contains(Filenames *head, char *filename);
//打印list
void print_filelist(Filenames *head);

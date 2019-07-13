#include "filename_list.h"

Filenames *create_filelist()
{
	Filenames *head;
	head = (Filenames*)malloc(sizeof(Filenames));
	//snprintf(head->filename, sizeof(head->filename), "head");
	head->next = NULL;
	printf("create list\n");
	return head;
}

void insert_to_filelist(Filenames *head, char *filename, int len)
{
	Filenames *node = head;
	while(node->next != NULL) {
		node = node->next;
	}
	
	Filenames *node_tmp = (Filenames*)malloc(sizeof(Filenames));
	node_tmp->filename = malloc(len + 1);
	snprintf(node_tmp->filename, len + 1, "%s", filename);
	node_tmp->next = NULL;
	node->next = node_tmp;
}

Filenames *clear_filelist(Filenames *head)
{
	Filenames *node = head->next;
	while(node != NULL) {
		Filenames *tmp = node;
		node = node->next;
		free(tmp->filename);
		free(tmp);
		tmp->filename = NULL;
		tmp = NULL;
	}

	return head;
}

int if_contains(Filenames *head, char *filename)
{
	Filenames *node = head->next;
	while(node != NULL) {
		if(strcmp(node->filename, filename) == 0) {
			return 1;
		}
		node = node->next;
	}
	return 0;
}

void print_filelist(Filenames *head)
{
	Filenames *node = head->next;
	//printf("node = %s\n", node);
	while(node != NULL) {
		printf("filename = %s\n", node->filename);
		node = node->next;
	}
}


int main()
{
	Filenames *head = create_filelist();
	insert_to_filelist(head, "firefox", 7);
	insert_to_filelist(head, "chrome", 7);
	insert_to_filelist(head, "weixin", 10);
	print_filelist(head);
	printf("=================\n");
	printf("contains chrome? %d\n", if_contains(head, "firefox"));
	printf("=================\n");
	clear_filelist(head);
	print_filelist(head);
	return 0;
}

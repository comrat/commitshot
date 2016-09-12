#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "history.h"


bool check_history_file()
{
	char* uname = getlogin();
	char* home = "/home/";
	char* file_name = "/.bash_history\0";
	int len = strlen(uname) + strlen(home) + strlen(file_name);
	char history_file[len];
	FILE *fp;

	strcpy(history_file, home);
	strcat(history_file, uname);
	strcat(history_file, file_name);

	fp = fopen(history_file, "r");
	return fp != NULL;
}


bool check_size_changed()
{
	char* uname = getlogin();
	char* home = "/home/";
	char* file_name = "/.bash_history\0";
	int len = strlen(uname) + strlen(home) + strlen(file_name);
	char history_file[len];
	FILE *fp;
	long file_size;
	bool res;

	strcpy(history_file, home);
	strcat(history_file, uname);
	strcat(history_file, file_name);

	fp = fopen(history_file, "r");
	if (fp == NULL)
		return 0;

	fseek(fp, 0, SEEK_END);
	file_size = ftell(fp);
	file_size = (file_size >= 0) ? file_size : -1;
	res = (file_size >= 0 && file_size != CURRENT_SIZE);
	printf("%lu - %lu\n", file_size, CURRENT_SIZE);
	CURRENT_SIZE = file_size;
	return res;
}


bool check_last_command()
{
	char* uname = getlogin();
	char* line = NULL;
	char* commit = NULL;
	ssize_t read;
	char* home = "/home/";
	char* file_name = "/.bash_history\0";
	size_t len = strlen(uname) + strlen(home) + strlen(file_name);
	char history_file[len];
	FILE *fp;
	long file_size;

	strcpy(history_file, "/home/");
	strcat(history_file, uname);
	strcat(history_file, "/.bash_history\0");

	fp = fopen(history_file, "r");

	fseek(fp, 0, SEEK_END);
	file_size = ftell(fp);
	printf("Size %lu\n", file_size);
	fseek(fp, 0, 0);


	if (!fp) {
		printf("Failed to open history");
		return FALSE;
	}

	while ((read = getline(&line, &len, fp)) != -1) ;
	//printf("%s", line);

	commit = strstr(line, "commit");
	if (commit)
		printf("FOND!\n");
	else
		printf("NOT FOND!\n");

	fclose(fp);
	if (line)
		free(line);

	return TRUE;
}

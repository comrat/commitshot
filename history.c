#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "history.h"


int check_history_file()
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

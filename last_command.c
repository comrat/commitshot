#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	char* uname = getlogin();
	char* line = NULL;
	char* commit = NULL;
	ssize_t read;
	int len = strlen(uname) + 21;
	char history_file[len];
	FILE *fp;

	strcpy(history_file, "/home/");
	strcat(history_file, uname);
	strcat(history_file, "/.bash_history\0");
	fp = fopen(history_file, "r");
	if (!fp) {
		printf("Failed to open history");
		return -1;
	}

	while ((read = getline(&line, &len, fp)) != -1) ;
	printf("%s", line);

	commit = strstr(line, "commit");
	if (commit)
		printf("FOND!\n");
	else
		printf("NOT FOND!\n");

	fclose(fp);
	if (line)
		free(line);

	return 0;
}
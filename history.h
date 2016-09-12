#ifndef HISTORY_H
#define HISTORY_H

#define FALSE	0
#define TRUE	1

typedef int bool;


long CURRENT_SIZE = -1;

bool check_history_file();
bool check_size_changed();
bool check_last_command();

#endif

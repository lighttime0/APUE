#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	if (argc != 2){
		printf("usage: get_file_description <descriptor #>\n");
		exit(0);
	}

	int val = fcntl(atoi(argv[1]), F_GETFL, 0);
	if (val < 0) {
		printf("fcntl error for fd %d\n", atoi(argv[1]));
		exit(0);
	}

	switch(val & O_ACCMODE) {
	case O_RDONLY:
		printf("read only");
		break;
	case O_WRONLY:
		printf("write only");
		break;
	case O_RDWR:
		printf("read write");
		break;
	default:
		printf("unknown access mode");
	}

	if (val & O_APPEND)
		printf(", append");
	if (val & O_NONBLOCK)
		printf(", nonblocking");
	if (val & O_SYNC)
		printf(", synchronous writes");

	printf("\n");
	exit(0);
}
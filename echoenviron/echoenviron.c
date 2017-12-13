#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int max_env = 7;
const char *environ[max_env] = {
	"HOME",
	"LOGNAME",
	"PATH",
	"PWD",
	"SHELL",
	"TERM",
	"TZ"
};
const char *environ_comment[max_env] = {
	"The HOME root direction",
	"Log name",
	"The path of execusions",
	"Print current work direction",
	"The default shell",
	"Terminal type",
	"Time zone"
};

int
check(char *arg)	//Check if arg is in environ[], if it does, return 1, else return 0.
{
	int res = 0;
	int i;
	for (i = 0; i < max_env; ++i) {
		if (strcmp(environ[i], arg) == 0) {
			res = 1;
			break;
		}
	}
	return res;
}

int
main(int argc, char *argv[])
{
	int i;
	if (strcmp(argv[1],"-help") == 0) {
		printf("echoenviron: \n");
		printf("\t A small tool that can print some shell environments.\n");
		printf("\t Your may add more than one argument, seperate with white space.\n\n");
		printf("Your can print these environments: \n");
		for (i = 0; i < max_env; ++i)
			printf("\t %s : %s\n", environ[i], environ_comment[i]); 
		exit(0);
	}
	for (i = 1; i < argc; ++i) {
		if (check(argv[i])) {
			printf("%s : %s\n", argv[i], getenv(argv[i]));
		} else {
			printf("Wrong arguments! \nType in './echoenviron -help' for guide\n");
		}
	}
	exit(0);
}
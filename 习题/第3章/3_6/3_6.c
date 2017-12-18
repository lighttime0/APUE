/*
* 经编成验证，使用O_APPEND标识打开的文件，
* 可以用lseek从任意位置开始读，
* 但是不能用lseek更新任意部分数据，只能在文件末尾加数据。
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int
main(void)
{
	const int buff_size = 10;
	char buf_write[buff_size + 1] = "0123456789";
	char buf_read[buff_size + 1];

	off_t offset = 12;

	int fd = open("content.txt", O_RDWR | O_APPEND);
	if (fd < 0) {
		printf("fd open error.\n");
		exit(1);
	}
	
	if (lseek(fd, offset, SEEK_SET) == -1) {
		printf("lseek error.\n");
		exit(1);
	}

	if (read(fd,buf_read,buff_size) != buff_size) {
		printf("read error.\n");
		exit(1);
	} else {
		printf("%s\n", buf_read);
	}


	if (write(fd, buf_write, buff_size) != 10) {
		printf("write error.\n");
		exit(0);
	}

	printf("write to content.txt successfully.\n");
	exit(0);
}
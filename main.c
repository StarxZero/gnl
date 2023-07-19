#include "get_next_line.h"

int main()
{
	int fd = open("test", O_RDONLY);
	printf("1:%s", get_next_line(fd));
	printf("2:%s", get_next_line(fd));
	printf("3:%s", get_next_line(fd));
	printf("4:%s", get_next_line(fd));
	printf("5:%s", get_next_line(fd));
	printf("6:%s", get_next_line(fd));
}

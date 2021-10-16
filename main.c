#include <stdio.h>
#include "get_next_line.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int fd;
	char *line;
	char c = 'a';
	line = &c;

	if (argc != 2)
	{
		printf("Please type the name of one file to read the first line from\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening the file\n");
		return (1);
	}
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}
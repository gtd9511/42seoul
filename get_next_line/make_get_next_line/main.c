#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

int	main(void)
{
	char			*line;
	int				fd;
	int				i;

	fd = open("shanghai.txt", O_RDONLY);
	if (!fd)
		return (1);
	i = 0;
	while (i++ < 300)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
	close(fd);
	system("leaks a.out");
	return (0);
}

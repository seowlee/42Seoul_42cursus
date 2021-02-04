#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		res;

	fd = open("ttest", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		res = get_next_line(fd, &line);
		printf("line : %s\n", line);
		printf("return value : %d\n", res);
		free(line);
	}
	printf("line : %s\n", line);
	printf("return value : %d\n", res);
	free(line);

	return (0);
}

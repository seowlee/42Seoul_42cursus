#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		res;

	fd = open("ttest", O_RDONLY);
	res = get_next_line(fd, &line);
	while (res)
	{
		printf("line : %s\n", line);
		printf("return value : %d\n", res);
		free(line);
	}
	printf("line : %s\n", line);
	printf("return value : %d\n", res);
	free(line);

	return (0);
}

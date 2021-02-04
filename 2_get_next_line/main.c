#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		res;

	fd = open("ttest", O_RDONLY);
	while ((res = get_next_line(fd, &line)) > 0)
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

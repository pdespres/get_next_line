#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char    *str;
	int     fd;
	int		ind;
	int		ret;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	ind = 1;
//	close(fd);
//	printf("%zd\n", read(fd, buf, BUFF_SIZE));
	while (1)
	{
		ret = get_next_line(fd, &str);
		printf("%d result %d %s\n", ind, ret, str);
		if (ret <= 0)
			break ;
		ind++;
	}
	return (0);
}

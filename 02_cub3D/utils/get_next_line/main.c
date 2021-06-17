#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int	r;
	char	*line;

	line = NULL;
	while ((r = get_next_line(1, &line, 1)) > 0)
	{
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
}


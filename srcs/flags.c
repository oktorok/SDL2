#include "../includes/header.h"

int	set_flags(int argn, char **argv)
{
	int	i[2];
	int	flag;

	flag = 0;
	i[0] = 1;
	while (i[0] < argn)
	{
		i[1] = 0;
		if (argv[i[0]][i[1]] == '-')
		{
			while (argv[i[0]][++i[1]])
			{
				if (argv[i[0]][i[1]] >= 97 && argv[i[0]][i[1]] <= 122)
					flag = flag | (1 << (argv[i[0]][i[1]] - 97));
			}
		}
		i[0]++;
	}
	return (flag);
}

int check_flags(int flags, char flag)
{
	if (flags & (1 << (flag - 97)))
		return (1);
	return (0);
}

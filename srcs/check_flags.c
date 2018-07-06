#include "header.h"

int check_flags(int flags, char flag)
{
	if (flags & (1 << (flag - 97)))
		return (1);
	return (0);
}

#include "corewar.h"

void	cw_perror_exit(char *message, int error_number)
{
	perror(message);
	cw_free();
	exit(error_number);
}

void	cw_exit(char *message, int error_number)
{
	ft_dprintf(2, "%s\n", message);
	cw_free();
	exit(error_number);
}

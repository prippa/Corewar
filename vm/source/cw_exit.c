#include "corewar.h"

void	cw_perror_exit(char *message, int error_number)
{
	perror(message);
	cw_free();
	exit(error_number);
}

void	cw_exit(char *message, int error_number)
{
	if (error_number == HEADER)
		ft_dprintf(2, "ERROR: File [%s] has an invalid header\n", message);
	else if (error_number == PROG_NAME)
		ft_dprintf(2, "ERROR: File [%s] prog name lenght is not equally \
to PROG_NAME_LENGTH\n", message);
	else
		ft_dprintf(2, "%s\n", message);
	cw_free();
	exit(error_number);
}

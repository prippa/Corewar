#include "corewar.h"

int		main(int argc, char **argv)
{
	cw_init();
	cw_parser(argc, argv);
	cw_free();
	system("leaks -q corewar");
	return (0);
}

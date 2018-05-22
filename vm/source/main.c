#include "corewar.h"

int		main(int argc, char **argv)
{
	cw_init();
	cw_parse_args(argc, argv);
	cw_parser();
	cw_free();
	system("leaks -q corewar");
	return (0);
}

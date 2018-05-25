#include "corewar.h"

void			cw_lseek_cur_skip(int fd, long size)
{
	if ((lseek(fd, size, SEEK_CUR)) < 0)
		cw_perror_exit(ERR_LSEEK_CUR_MESSAGE, LSEEK);
}

unsigned int	cw_hex_to_dec(unsigned char (*str)[])
{
	unsigned int res;

	res = 0;
	res += (*str)[0] * 16777216;
	res += (*str)[1] * 65536;
	res += (*str)[2] * 256;
	res += (*str)[3];
	return (res);
}

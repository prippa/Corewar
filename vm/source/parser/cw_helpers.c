/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:55:14 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:55:20 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			cw_lseek_cur_skip(int fd, long size)
{
	if ((lseek(fd, size, SEEK_CUR)) < 0)
		cw_perror_exit(ERR_LSEEK_CUR_MESSAGE, LSEEK);
}

long long int	cw_hex_to_dec(unsigned char *buf)
{
	long long int res;

	res = 0;
	res += buf[0] * 16777216;
	res += buf[1] * 65536;
	res += buf[2] * 256;
	res += buf[3];
	return (res);
}

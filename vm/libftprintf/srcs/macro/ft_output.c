/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 11:51:24 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/13 18:18:10 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_output(const int fd,
		const char *output,
		int *const length)
{
	int	len;

	len = (int)ft_strlen(output);
	if (!(*length))
		*length = len;
	else
		*length += len;
	write(fd, output, len);
	return (*length);
}

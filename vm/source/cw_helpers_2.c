/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_helpers_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:46:14 by prippa            #+#    #+#             */
/*   Updated: 2018/06/12 18:46:15 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char			*cw_snoop_dogg(char *str)
{
	char *wuf_wuf;

	if (!(wuf_wuf = ft_strnew(32)))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);

	ft_strncpy(wuf_wuf, &str[32], 32);

	return (wuf_wuf);

}

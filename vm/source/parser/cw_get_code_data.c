/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_code_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:02:41 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 17:02:44 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_get_code_data(t_champ *champ)
{
	ft_printf("%d\n", 4294967286);
	for (int i = 0; i < champ->head.prog_size; i++)
		ft_printf("%u ", (unsigned char)champ->code[i]);
}

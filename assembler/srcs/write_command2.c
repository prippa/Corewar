/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:43:00 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/21 14:05:56 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			t_check(char *s, t_asm *am, t_label *lb)
{
	
}

static void		write_cod8(char *s, t_asm *am, char *cmd, t_label *lb)
{

}

static void		write_cod7(char *s, t_asm *am, char *cmd, t_label *lb)
{
	if (i != 11)
		write_cod8(s, am, i, lb);
	else
	{

	}
}

void			write_cod6(char *s, t_asm *am, char *cmd, t_label *lb)
{
	if (i != 10 && i != 14)
		write_cod7(s, am, i, lb);
	else
	{
		
	}
}

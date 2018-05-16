/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 23:33:49 by vgladush          #+#    #+#             */
/*   Updated: 2018/04/23 19:14:43 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_form(char *s, t_asm *am, int i)
{
	if (!am->name || !am->comment)
		errors_man(am, s, 4);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (!s[i] || s[i] == '#' || s[i] == ';')
		return ;
}

void		conver_bn(t_asm *am, char *s, int i, int j)
{
	char	*tmp;
	char	*res;

	tmp = 0;
	if (!(res = ft_strnew(0)))
		return ;
	while (s[am->x + j] && s[am->x + j] != '\"')
	{
		if (j && !(j % 2))
			res = ft_joinfree(res, " ", 1);
		if (ft_strlen((tmp = ft_itoabase(s[am->x + j++], 16, 'a'))) < 2)
			tmp = ft_joinfree("0", tmp, 2);
		res = ft_joinfree(res, tmp, 3);
	}
	while ((i == 1 && j < 128) || (i == 2 && j < 2048))
	{
		if (++j && !((j - 1) % 2))
			res = ft_joinfree(res, " ", 1);
		res = ft_joinfree(res, "00", 1);
	}
	if (i == 1)
		am->name = ft_strdup(res);
	else
		am->comment = ft_strdup(res);
	free(res);
}

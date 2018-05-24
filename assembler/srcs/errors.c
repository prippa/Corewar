/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:58:44 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/24 18:10:51 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	errors_thr(t_asm *am, int o)
{
	char	*st;

	st = tran_str(o - (o > 40 ? 40 : 20));
	if (o > 40)
		ft_printf("One or more parameters are missing in the instruction \
\"%s\" [%d:%d]\n", st, am->y, am->x);
	else
		ft_printf("Invalid parameter for instruction \"%s\" \
[%d:%d]\n", st, am->y, am->x);
	if (st)
		free(st);
}

static void	errors_sec(t_asm *am, int o)
{
	if (o == 5)
		ft_printf("Syntax error at token [TOKEN]\
[%.3d:%.3d] END \"(null)\"\n", am->y, am->x + 1);
	else if (o == 6)
		ft_printf("Champion name too long (Max length 128)\n");
	else if (o == 7)
		ft_printf("Champion comment too long (Max length 2048)\n");
	else if (o == 8)
		ft_printf("Champion comment too long (Max length 2048)\n");
	else if (o == 9)
		ft_printf("Lexical error at [%d:%d]\n", am->y, am->x);
	else if (o == 10)
		ft_printf("malloc ERROR: could not allocate memory\n");
	else if (o == 11)
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
no name and/or comment of the champion. The champion's name \
and comment should be before any operations \"", am->y, am->x + 1);
	else
		errors_thr(am, o);
}

void		errors_man(t_asm *am, char *s, int o)
{
	if (!o)
		ft_printf("Lexical error at [%d:%d] there is no such command \"",
		am->y, am->x);
	else if (o == 1)
		ft_printf("Syntax error at token [TOKEN]\
[%.3d:001] second COMMAND_NAME \".name\"\n", am->y);
	else if (o == 2)
		ft_printf("Syntax error at token [TOKEN]\
[%.3d:001] second COMMAND_COMMENT \".comment\"\n", am->y);
	else if (o == 3)
		ft_printf("Syntax error at token [TOKEN]\
[%.3d:%.3d] ENDLINE\n", am->y, am->x + 1);
	else if (o == 4)
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] INSTRUCTION \"",
			am->y, am->x);
	else
		errors_sec(am, o);
	if (!o || o == 4 || o == 11 || o == 12)
	{
		while (s[am->x] && ft_strchr(LABEL_CHARS, s[am->x]))
			write(1, s + am->x++, 1);
		write(1, "\"\n", 2);
	}
	// all_clear(am, s);
	exit(1);
}

void		bef_error(char *s, t_asm *am, char cmd, int i)
{
	if (!i && (!s[am->x] || s[am->x] == COMMENT_CHAR || s[am->x] == ';'))
		return ;
	if (!i && ft_strchr(LABEL_CHARS, s[am->x]))
		errors_man(am, s, 4);
	if (!i)
		errors_man(am, s, 9);
	if (!s[am->x] && s[am->x] == COMMENT_CHAR && s[am->x] == ';')
	{
		am->x = ft_strlen(s);
		errors_man(am, s, 40 + cmd);
	}
	else
		errors_man(am, s, 20 + cmd);
}

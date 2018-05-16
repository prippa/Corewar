/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:21:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/04/23 19:17:31 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../libft/includes/libft.h"

typedef struct		s_asm
{
	char			*name;
	char			*comment;
	char			*bn;
	char			*cmd;
	int				x;
	int				y;
}					t_asm;

void				errors_man(t_asm *am, char *s, int o);
void				check_form(char *s, t_asm *am, int i);
void				conver_bn(t_asm *am, char *s, int i, int j);

#endif

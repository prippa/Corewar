/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:33:11 by prippa            #+#    #+#             */
/*   Updated: 2018/05/30 13:33:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

<<<<<<< HEAD
t_command		*t_command_mem(void) // for one element;
=======
t_command		*t_command_mem(void)
>>>>>>> prippa
{
	t_command *new_obj;

	if (!(new_obj = (t_command *)malloc(sizeof(t_command))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	new_obj->cmd = 0;
	new_obj->codage = 0;
	new_obj->arg1.av = 0;
	new_obj->arg1.tp = 0;
	new_obj->arg2.av = 0;
	new_obj->arg2.tp = 0;
	new_obj->arg3.av = 0;
	new_obj->arg3.tp = 0;
	return (new_obj);
}

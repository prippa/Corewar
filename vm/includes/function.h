/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:48:47 by prippa            #+#    #+#             */
/*   Updated: 2018/04/26 18:48:49 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

/*
** Basics
*/

void			cw_exit(char *message, int error_number);
void			cw_perror_exit(char *message, int error_number);
void			cw_init(void);
void			cw_free(void);

/*
** End
*/

/*
** Parse file part
*/

long long int	cw_hex_to_dec(unsigned char *buf);
void			cw_lseek_cur_skip(int fd, long size);
void			cw_check_magic(t_champ *champ);
void			cw_get_prog_name(t_champ *champ);
void			cw_get_prog_size(t_champ *champ);
void			cw_get_comment(t_champ *champ);
void			cw_get_prog_code(t_champ *champ);
void			cw_get_code_data(t_champ *champ);
void			cw_parse_args(int argc, char **argv);
void			cw_parser(void);

/*
** End
*/

/*
** List Manipulations
*/

void			t_command_add(t_command **cmds);
void			t_command_free(t_command **cmds);
void			t_champ_add(t_champ **champs);
void			t_champ_free(t_champ **champs);

/*
** End
*/

#endif

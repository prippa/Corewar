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

void		cw_exit(char *message, int error_number);
void		cw_perror_exit(char *message, int error_number);
void		cw_init(void);
void		cw_free(void);

/*
** End
*/

/*
** Parse file part
*/

void		cw_parse_args(int argc, char **argv);
void		cw_parser(void);

/*
** End
*/

/*
** List Manipulations
*/

void		t_champ_add(t_champ **champs);
void		t_champ_free(t_champ **champs);

/*
** End
*/

#endif

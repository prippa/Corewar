/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinmacro.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:54:49 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 14:55:47 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOINMACRO_H
# define JOINMACRO_H
# include "datastructs.h"

void	join_none(t_pfargs *pf);
void	join_n(t_pfargs *pf);
void	join_t(t_pfargs *pf);
void	join_r(t_pfargs *pf);
void	join_big_s(t_pfargs *pf);
void	join_big_c(t_pfargs *pf);
void	join_signed_decimal(t_pfargs *pf);
void	join_unsigned_value(t_pfargs *pf);
void	join_c(t_pfargs *pf);
void	join_s(t_pfargs *pf);
void	join_percent(t_pfargs *pf);
void	join_p(t_pfargs *pf);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:48:32 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 18:01:31 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		join_null_symbol_minus_flag(t_pfargs *pf)
{
	char		*until;
	int			length;
	int			null_pos;
	char		*new_out;

	length = (int)ft_strlen(pf->output);
	null_pos = length - pf->spec.width;
	until = ft_strnew(null_pos);
	ft_memmove(until, pf->output, null_pos);
	ft_output(pf->fd, until, &(pf->length));
	write(pf->fd, "\000", 1);
	(pf->length)++;
	new_out = ft_strnew(length - null_pos - 1);
	ft_memmove(new_out, pf->output + null_pos + 1, length - null_pos - 1);
	ft_strdel(&(pf->output));
	ft_strdel(&until);
	pf->output = new_out;
}

static void		join_null_symbol(t_pfargs *pf)
{
	t_value		*element;

	element = ((t_value *)((pf->t)->content));
	element->value = init_min_str('*');
	join_value(&(pf->output), element->value, pf->spec);
	if (pf->spec.width >= 2 && pf->spec.minus_flag)
	{
		join_null_symbol_minus_flag(pf);
	}
	else
	{
		(pf->output)[(int)ft_strlen(pf->output) - 1] = '\000';
		ft_output(pf->fd, pf->output, &(pf->length));
		pf->output = ft_strdup("");
		(pf->length)++;
		write(pf->fd, "\000", 1);
	}
}

void			join_c(t_pfargs *pf)
{
	int			my_char;
	t_value		*element;

	my_char = va_arg(pf->argptr, int);
	if (my_char)
	{
		element = ((t_value *)((pf->t)->content));
		element->value = init_min_str(my_char);
		join_value(&(pf->output), element->value, pf->spec);
	}
	else
		join_null_symbol(pf);
}

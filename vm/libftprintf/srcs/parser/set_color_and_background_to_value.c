/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_and_background_to_value.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 15:10:19 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 18:48:41 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_strjoin_free(char *str1,
		char *str2,
		t_bool f1,
		t_bool f2)
{
	char			*result;

	result = ft_strjoin(str1, str2);
	if (f1 == TRUE)
		ft_strdel(&str1);
	if (f2 == TRUE)
		ft_strdel(&str2);
	return (result);
}

static inline void	set_both(char **value, t_spec spec)
{
	char			*color;

	color = ft_strjoin_free("\x1b[38;2;",
			ft_strjoin_free(ft_itoa(spec.color.r), ";", TRUE, FALSE),
			FALSE, TRUE);
	color = ft_strjoin_free(color,
			ft_strjoin_free(ft_itoa(spec.color.g), ";", TRUE, FALSE),
			TRUE, TRUE);
	color = ft_strjoin_free(color,
			ft_strjoin_free(ft_itoa(spec.color.b), ";48;2;", TRUE, FALSE),
			TRUE, TRUE);
	color = ft_strjoin_free(color,
			ft_strjoin_free(ft_itoa(spec.background.r), ";", TRUE, FALSE),
			TRUE, TRUE);
	color = ft_strjoin_free(color,
			ft_strjoin_free(ft_itoa(spec.background.g), ";", TRUE, FALSE),
			TRUE, TRUE);
	color = ft_strjoin_free(color,
			ft_strjoin_free(ft_itoa(spec.background.b), "m", TRUE, FALSE),
			TRUE, TRUE);
	*value = ft_strjoin_free(color, *value, TRUE, TRUE);
	*value = ft_strjoin_free(*value, "\x1b[0m", TRUE, FALSE);
}

static inline void	set_only_color(char **value, t_spec spec)
{
	char			*color;

	color = ft_strjoin_free("\x1b[38;2;",
		ft_strjoin_free(ft_itoa(spec.color.r), ";", TRUE, FALSE),
		FALSE, TRUE);
	color = ft_strjoin_free(color,
		ft_strjoin_free(ft_itoa(spec.color.g), ";", TRUE, FALSE),
		TRUE, TRUE);
	color = ft_strjoin_free(color,
		ft_strjoin_free(ft_itoa(spec.color.b), "m", TRUE, FALSE),
		TRUE, TRUE);
	*value = ft_strjoin_free(color, *value, TRUE, TRUE);
	*value = ft_strjoin_free(*value, "\x1b[0m", TRUE, FALSE);
}

static inline void	set_only_background(char **value, t_spec spec)
{
	char			*color;

	color = ft_strjoin_free("\x1b[48;2;",
		ft_strjoin_free(ft_itoa(spec.background.r), ";", TRUE, FALSE),
		FALSE, TRUE);
	color = ft_strjoin_free(color,
		ft_strjoin_free(ft_itoa(spec.background.g), ";", TRUE, FALSE),
		TRUE, TRUE);
	color = ft_strjoin_free(color,
		ft_strjoin_free(ft_itoa(spec.background.b), "m", TRUE, FALSE),
		TRUE, TRUE);
	*value = ft_strjoin_free(color, *value, TRUE, TRUE);
	*value = ft_strjoin_free(*value, "\x1b[0m", TRUE, FALSE);
}

void				set_color_and_background_to_value(char **value, t_spec spec)
{
	t_bool			color_flag;
	t_bool			background_flag;

	color_flag = spec.color.r ||
	spec.color.g ||
	spec.color.b;
	background_flag = spec.background.r ||
	spec.background.g ||
	spec.background.b;
	if (color_flag && background_flag)
		set_both(value, spec);
	else if (color_flag)
		set_only_color(value, spec);
	else if (background_flag)
		set_only_background(value, spec);
}

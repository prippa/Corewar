/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:33:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/26 14:55:31 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_string_size(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (len > -1 && str[len] != '/')
	{
		i++;
		len--;
	}
	return (i);
}

static int		len_to_copy(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (str[len] && str[len] != '.' && str[len] != '/')
	{
		i++;
		len--;
	}
	if (ft_string_size(str) == i)
		return (0);
	return (i + 1);
}

char			*generate_file_name(char *file_string)
{
	int		len;
	int		copy_start;
	char	*tmp;
	char	*res;

	len = ft_string_size(file_string);
	copy_start = ft_strlen(file_string) - len;
	tmp = ft_strnew(len - len_to_copy(file_string));
	ft_strncpy(tmp, &file_string[copy_start], len - len_to_copy(file_string));
	res = ft_strjoin(tmp, ".cor");
	free(tmp);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:33:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/27 18:27:17 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*generate_file_name(char *file_string)
{
	int		len;
	char	*res;

	len = ft_strlen(file_string) - 1;
	while (len > 0 && file_string[len] != '/' && file_string[len] != '.')
		len--;
	if (!len || file_string[len] == '/')
		len = ft_strlen(file_string);
	file_string[len] = 0;
	res = ft_strjoin(file_string, ".cor");
	return (res);
}

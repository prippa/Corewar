/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   force_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 18:35:02 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 18:35:04 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	force_error(const char *error)
{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
							"Error!",
							error,
							NULL);
}

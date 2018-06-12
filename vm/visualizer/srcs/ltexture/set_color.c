/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 19:01:36 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/29 19:01:38 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	set_color(SDL_Color c, t_ltexture *ltexture)
{
	SDL_SetTextureColorMod(ltexture->texture, c.r, c.g, c.b);
}

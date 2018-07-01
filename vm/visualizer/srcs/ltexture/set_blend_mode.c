/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_blend_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:13:12 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/30 14:13:14 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	set_blend_mode(SDL_BlendMode blend, t_ltexture *ltexture)
{
	SDL_SetTextureBlendMode(ltexture->texture, blend);
}

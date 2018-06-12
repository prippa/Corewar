/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltexture.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:01:14 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/29 18:01:57 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LTEXTURE_H
# define LTEXTURE_H
# include "base.h"

/*
** Returns position for render function
*/
t_rposition				get_render_position(double angle,
											SDL_Point *left_corner,
											SDL_Point *center,
											SDL_Rect *clip);
											
/*
** Loads image at specified path
*/
t_ltexture				*load_from_file(const char *path,
										SDL_Renderer *renderer,
										SDL_Color color_key);
/*
** Deallocates texture
*/
void					free_ltexture(t_ltexture *ltexture);

/*
** Renders texture at given point
*/
void					render(t_rposition *position,
								t_ltexture *ltexture,
								SDL_Renderer *renderer,
								SDL_RendererFlip flip);

/*
** Sets color modulation
*/
void					set_color(SDL_Color rgb,
									t_ltexture *ltexture);

/*
** Sets blend mode
*/
void					set_blend_mode(SDL_BlendMode blend,
										t_ltexture *ltexture);

/*
** Sets alpha mode
*/
void					set_alpha_mode(Uint8 alpha,
										t_ltexture *ltexture);

/*
** Creates image from given font string
*/
t_ltexture				*load_from_rendered_text(t_text text_info,
													SDL_Renderer *renderer);


/*
** Creates temporary context for rendering text
*/
t_text					get_text_info(const char *font_name,
										int font_weight,
										const char *txt,
										SDL_Color txt_color);
#endif

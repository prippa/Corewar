/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:44:52 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/22 15:44:55 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H
# include "button.h"
# include "events.h"
# include "draw.h"
# include "loader.h"
# include "ltexture.h"
# include "fonts.h"
# include "init.h"
# define ARENA_TILE_WIDTH (((int)((0.9 * SCREEN_WIDTH) - BUTTON_WIDTH)) >> 6)
# define ARENA_TILE_HEIGHT (SCREEN_HEIGHT >> 6)
# define ARENA_WIDTH 64
# define ARENA_HEIGHT 64

int			visualizer_main(void);
SDL_Rect	get_rectangle(int x, int y, int w, int h);
void		set_viewport(SDL_Renderer *renderer, SDL_Rect *viewport);
void		clear_renderer(SDL_Renderer *renderer);
int			exit_dialog(t_arena *arena);
void		set_random(t_arena *arena);
void		force_error(const char *error);
void		get_digits(unsigned char hex, int *ff, int *sf);
void		render_part(SDL_Rect clip,
						SDL_Rect target,
						SDL_Point top_left,
						SDL_Texture *texture,
						SDL_Renderer *renderer);
#endif

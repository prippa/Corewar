/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:48:47 by prippa            #+#    #+#             */
/*   Updated: 2018/04/26 18:48:49 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

/*
************************************ Basics ************************************
*/

void			cw_exit(char *message, int error_number);
void			cw_perror_exit(char *message, int error_number);
void			cw_print_dump_exit(void);
void			cw_init(void);
void			cw_free(void);

/*
************************************ Helpers ***********************************
*/

char			*cw_snoop_dogg(char *str);
int				cw_get_dec_from_the_point(unsigned char *str, int position);
int				cw_hex_to_dec(unsigned char *buf, int i);
void			cw_write_bytes_to_buf(unsigned char *buf, int nbr);
void			cw_write_to_map(t_stack *map, t_processes *proc,
					unsigned char *buf, int position_on_the_map);

/*
******************************* Parse file part ********************************
*/

int				cw_get_command(t_command *cmd, unsigned int i,
					unsigned char *map);

int			cw_get_command_2(t_command *cmd, unsigned int i,
			unsigned char *map, int proc_current_command);





void			cw_lseek_cur_skip(int fd, long size);
void			cw_check_magic(t_champ *champ);
void			cw_get_prog_name(t_champ *champ);
void			cw_get_prog_size(t_champ *champ);
void			cw_get_comment(t_champ *champ);
void			cw_get_prog_code(t_champ *champ);
int				cw_parse_flags(char **argv);
void			cw_parse_args(int argc, char **argv);
void			cw_parser(void);

/*
***************************** Struct Manipulations *****************************
*/

void			t_champ_sort_by_order(t_champ **champs);
void			t_champ_sort_by_champ_number(t_champ **champs);
void			t_champ_rev(t_champ **champs);
void			t_champ_add(t_champ **champs);
void			t_champ_free(t_champ **champs);
t_champ			*t_champ_find(int champ_number, t_champ *list);
unsigned int	t_champ_get_lives_number(t_champ *champs);
int				t_champ_check_double_champ_number(t_champ *champs,
					int order);
void			t_champ_zero_lives_number(t_champ *champs);

void			t_processe_add(t_processes **proc_start,
					t_processes **proc_end);
void			t_processes_copy(t_processes **proc_start,
					t_processes **proc_end, t_processes **current_proc,
					int position);
t_processes		*t_processe_get_by_id(t_processes *proc_start,
					t_processes *proc_end, unsigned int id);
int				t_processe_free_by_id(t_processes **proc_start,
					t_processes **proc_end, unsigned int id);
int				t_processe_free_by_obj(t_processes **proc_start,
					t_processes **proc_end, t_processes *obj);
void			t_processe_killer(t_champ *champs);

/*
********************************** Core Part ***********************************
*/

void			cw_load_map(void);
void			cw_game_loop(void);
void			cw_display_map(unsigned char *map, int *color);
void			cw_display_dump(void);
void			cw_cycles_new_period(void);
void			cw_print_players(t_champ *champs);
void			cw_print_winer(t_champ *champs);

/*
********************************** Functions ***********************************
*/

void			cw_binary_and(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/);
void			cw_binary_or(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/);
void			cw_binary_xor(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/);

void			cw_add(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/);
void			cw_sub(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/);

void			cw_sti(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/);
void			cw_live(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/);

void			cw_ld(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/);
void			cw_lld(t_command *cmd, t_stack *map, t_processes *proc);
void			cw_ldi(t_command *cmd, t_stack *map, t_processes *proc);
void			cw_lldi(t_command *cmd, t_stack *map, t_processes *proc);
void 			cw_zjmp(t_command *cmd, t_stack *map, t_processes *proc);
void			cw_aff(t_command *cmd, t_stack *map, t_processes *proc);

void			cw_st(t_command *cmd, t_stack *map, t_processes *proc);
void			cw_fork(t_command *cmd, t_stack *map, t_processes *proc);
void			cw_lfork(t_command *cmd, t_stack *map, t_processes *proc);

#endif

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

int				cw_get_dec_from_the_point(int pc, const int label);
int				cw_hex_to_dec(unsigned char *buf, int i);
void			cw_write_bytes_to_buf(unsigned char *buf, int nbr);
void			cw_write_to_map(unsigned char *buf, int pc);
int				cw_is_valid_reg(t_command *cmd);
void			cw_move_pc_with_codage(t_command *cmd, t_processes *proc);
void			cw_move_pc_without_codage(t_processes *proc);
void			cw_move_pc(t_processes *proc, int value);
int				cw_get_right_arg(t_processes *proc, char tp, int av);

/*
******************************* Parse file part ********************************
*/

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
int				t_champ_is_nbr_live(t_champ *champs);
int				t_champ_check_double_champ_number(t_champ *champs, int order);
void			t_champ_zero_lives_number(t_champ *champs);

void			t_processe_add(t_processes **proc_start,
					t_processes **proc_end);
void			t_processes_copy(t_processes **proc_start,
					t_processes **proc_end, t_processes *copy, int pc);
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
void			cw_print_players(t_champ *champs);
void			cw_print_winer(t_champ *champs);
void			cw_set_arg_tp_with_codage(t_command *cmd,
					char label, char comb);
void			cw_set_arg_av(t_command *cmd, int pc, char comb);

/*
********************************** Functions ***********************************
*/

void			cw_binary_and(t_processes *proc);
void			cw_binary_or(t_processes *proc);
void			cw_binary_xor(t_processes *proc);

void			cw_add(t_processes *proc);
void			cw_sub(t_processes *proc);

void			cw_sti(t_processes *proc);
void			cw_live(t_processes *proc);

void			cw_ld(t_processes *proc);
void			cw_lld(t_processes *proc);
void			cw_ldi(t_processes *proc);
void			cw_lldi(t_processes *proc);
void 			cw_zjmp(t_processes *proc);
void			cw_aff(t_processes *proc);

void			cw_st(t_processes *proc);
void			cw_fork(t_processes *proc);
void			cw_lfork(t_processes *proc);

/*
********************************** Colors ***********************************
*/

void			cw_refresh_colors(void);

#endif

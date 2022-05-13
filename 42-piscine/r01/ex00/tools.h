/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 19:04:15 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/15 23:25:47 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

//		ft_tools.c
void	ft_putchar(char c);

void	ft_putstr(char *str);

int		ft_strlen(char *str);

//		ft_check_av.c
int		ft_check_av(char *str);

void	ft_get_tower(char *str, int tower[16]);

//		ft_tab.c
void	ft_create_tab(int tab[4][4]);

void	ft_show_tab(int tab[4][4]);

int		ft_abs_on_axes(int val, int tab[4][4], int line, int column);

int		ft_make_tab(int tab[4][4], int pos, int tower[16]);

//		ft_valide_tower.c
int		ft_check_col_hb(int tab[4][4], int tower[16], int i);

int		ft_check_col_bh(int tab[4][4], int tower[16], int i);

int		ft_check_line_gd(int tab[4][4], int tower[16], int i);

int		ft_check_line_dg(int tab[9][4], int tower[16], int i);

int		ft_ok_tower(int val, int tab[4][4], int pos, int tower[16]);

#endif

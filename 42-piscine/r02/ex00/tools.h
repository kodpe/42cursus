/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:31:18 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/22 20:18:07 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h> //
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>

//for (int i = 0; i < nbr_lines +1; i++) // tmp
	//printf("%d > %s\n", i, dict[i]); // tmp

typedef struct s_key
{
	char	*num;
	char	*word;
}	t_key;

char	**ft_split(char *str, char *charset);

/*
 * ft_get_av.c
 */
int		ft_get_index_nbr(char *str);
int		ft_get_size_nbr(char *str, int i);
char	*ft_get_nbr(char *str);

/*
 * ft_tools_for_dictionary.c
 */
int	ft_get_index_dpt(char *str);
int	ft_get_index_key(char *str);
int	ft_get_len_nbr(char *str, int i);
int ft_check_value(char *str, int pos);

/*
 * ft_get_dictionary.c
 */
int		ft_count_lines(char *str);
int		ft_get_size_of_file(char *dict_name);
char	*ft_create_buffer(char *dict_name, int size);

/*
 * ft_check_dictionary.c
 */
void	ft_clean_key(char *str);
int		ft_check_line(char *str);
int		ft_check_dictionary(char **dict);
/*
 * utils.c
 */
int		ft_is_space(char c);
//char	*ft_strcpy(char *dest, char *src);
int		ft_strlen(char *str);
char	*ft_strxcpy(char *dest, char *src, int start, int end);
char	*ft_strxdup(char *src, int start, int end);

/*
 * utils2.c
 */
int		ft_dict_error(void);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);

/*
 * ft_create_struct.c
 */
t_key	*ft_putonstruct(char **dict, struct s_key *key);
t_key	*ft_declare_struct(int nbr_lines);
int		ft_check_double(t_key *key, int nbr_lines);
int		ft_check_keys(t_key *key, int nbr_lines);

/*
 * ft_trim.c
 */
int		trim_before_point(char *dict);
int		trim_after_point(char *dict, int begin);
void	trim_end(char *dict);
void	ft_trim(char **dict);

/*
 * ft_check_keys.c
 */
int	ft_first_check(t_key *key, int	nbr_lines);
int	ft_second_check(t_key *key, int	nbr_lines);
int	ft_third_check(t_key *key, int	nbr_lines);
int	ft_fourth_check(t_key *key, int nbr_lines);

/*
 * ft_free_all.c
 */
void	ft_free_dict(char **dict, int nbr_lines);
void	ft_free_key(t_key *key, int nbr_lines);

#endif

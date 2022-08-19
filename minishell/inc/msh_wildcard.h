/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_wildcard.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:59:01 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/28 14:11:31 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_WILDCARD_H
# define MSH_WILDCARD_H

typedef struct s_wildcard
{
	int	w_start_with;
	int	w_end_with;
}	t_wildcard;

int		init_wildcard(t_cmd	*cmd);
int		get_motif(char	*input, t_token **file);
int		get_files(t_token **file);
void	valid_motif(t_token *f, char **tab, t_wildcard *flag);
t_token	*filter_files(t_token *file, char *s);

#endif
/* MSH_WILDCARD_H */

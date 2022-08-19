/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:25:55 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 22:04:57 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_TOKEN_H
# define MSH_TOKEN_H

/* print_token str */
# define STR_T_FORBIDDEN	"T_FORBIDDEN   "
# define STR_T_ANDOR		"T_ANDOR       "
# define STR_T_PARENTHESIS	"T_PARENTHESIS "
# define STR_T_PIPE			"T_PIPE        "
# define STR_T_WHITESPACE	"T_WHITESPACE  "
# define STR_T_REDIR		"T_REDIR       "
# define STR_T_ENTREQUOTE	"T_ENTREQUOTE  "
# define STR_T_WORD			"T_WORD        "
# define STR_T_DEL			"T_DEL         "

# define NOT_WORD "&|\t\n \"'()<>;\\"
//! faire des tests avec tous les whitespace 9 -13

typedef enum e_tolkien
{
	T_FORBIDDEN,
	T_ANDOR,
	T_PARENTHESIS,
	T_PIPE,
	T_WHITESPACE,
	T_REDIR,
	T_ENTREQUOTE,
	T_WORD,
	T_DEL,
}	t_tolkien;

typedef struct s_token
{
	t_tolkien		name;
	char			*content;
	int				pos;
	size_t			size;
	int				is_concated;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

int		add_back(t_token **lst, t_token *new);
t_token	*cmd_end(t_token *lst);
t_token	*copylst(t_token *t);
t_token	*copy_lst_del(t_token *t);
t_token	*copy_lst_del_w(t_token *t);

t_token	*copy_lst_del_concat(t_token *t);
t_token	*new_token_c(t_tolkien name, char *content, int concat);

void	destroy_token_list(t_token **lst);
t_token	*new_token(t_tolkien name, char *content, size_t size);

void	print_token_list_one_line(t_token *t, char *caption, void (*c)(void));
void	print_token_list(t_token *t, char *caption);
void	print_one_token(t_token *t, char *caption);

t_token	*sublst(t_token *src, t_token *start, t_token *end);
t_token	*token_convert(char **splited);

t_token	*token_last(t_token *t);
size_t	token_size(t_token *t);
int		token_valid(t_token *lst, t_token *to_find);

t_token	*trim_parenthesis(t_token *t);

t_token	*add_token_list(t_token **ptr, t_token *expand);

void	sort_token_content(t_token	**file);

#endif /* MSH_TOKEN_H */

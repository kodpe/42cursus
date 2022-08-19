/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:22:37 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 19:32:36 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_token_name(t_tolkien name)
{
	if (name == T_FORBIDDEN)
		ft_dprintf(2, "%s", STR_T_FORBIDDEN);
	if (name == T_ANDOR)
		ft_dprintf(2, "%s", STR_T_ANDOR);
	if (name == T_PARENTHESIS)
		ft_dprintf(2, "%s", STR_T_PARENTHESIS);
	if (name == T_PIPE)
		ft_dprintf(2, "%s", STR_T_PIPE);
	if (name == T_WHITESPACE)
		ft_dprintf(2, "%s", STR_T_WHITESPACE);
	if (name == T_REDIR)
		ft_dprintf(2, "%s", STR_T_REDIR);
	if (name == T_ENTREQUOTE)
		ft_dprintf(2, "%s", STR_T_ENTREQUOTE);
	if (name == T_WORD)
		ft_dprintf(2, "%s", STR_T_WORD);
	if (name == T_DEL)
		ft_dprintf(2, "%s", STR_T_DEL);
}

// void	print_token(t_tolkien name, char *content, size_t size)
// {
// 	print_token_name(name);
// 	if (size < 10)
// 		ft_putstr_fd(" ", 2);
// 	ft_dprintf(2, " %d {%s}\n", size, content);
// 	(void)content;
// 	(void)size;
// }

void	print_one_token(t_token *t, char *caption)
{
	c_magenta();
	ft_dprintf(2, "%s\n", caption);
	c_yellow();
	ft_dprintf(2, "pos address    name            content\n");
	if (t->pos < 100)
		ft_putstr_fd(" ", 2);
	if (t->pos < 10)
		ft_putstr_fd(" ", 2);
	ft_dprintf(2, "%d %p  ", t->pos, t);
	print_token_name(t->name);
	ft_dprintf(2, "  {%s}\n", t->content);
	ft_putnl_fd(2);
	c_reset();
}

void	print_token_list_one_line(t_token *t, char *caption, void (*c)(void))
{
	c();
	if (caption)
		ft_dprintf(2, "%s\n", caption);
	ft_dprintf(2, "{");
	while (t)
	{
		if (t->name == T_WHITESPACE)
			ft_dprintf(2, " ");
		else
			ft_dprintf(2, "%s", t->content);
		t = t->next;
	}
	ft_dprintf(2, "}\n");
	c_reset();
}

void	print_token_list(t_token *t, char *caption)
{
	t_token	*root;

	root = t;
	c_magenta();
	ft_dprintf(2, "%s\n", caption);
	c_yellow();
	ft_dprintf(2, "pos address    name            content\n");
	while (t)
	{
		if (t->pos < 100)
			ft_putstr_fd(" ", 2);
		if (t->pos < 10)
			ft_putstr_fd(" ", 2);
		ft_dprintf(2, "%d %p  ", t->pos, t);
		print_token_name(t->name);
		ft_dprintf(2, "  {%s}", t->content);
		if (t->is_concated)
			ft_dprintf(2, "=========== Is concated =======\n");
		else
			write(2, "\n", 1);
		t = t->next;
	}
	print_token_list_one_line(root, NULL, c_green);
	ft_putnl_fd(2);
	c_reset();
}

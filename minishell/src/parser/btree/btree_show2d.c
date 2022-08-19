/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_show2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:01:01 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/01 17:29:43 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef enum e_slope
{
	SLOPE_NULL,
	SLOPE_TOP,
	SLOPE_BOT,
}			t_slope;

static void	btree_show_2d___(t_btree *root, int spaces, t_slope slope);

static void	___2d_andor(t_btree *root, int spaces, t_slope s)
{
	btree_show_2d___(root->left, spaces + 5, SLOPE_TOP);
	ft_putx_fd(2, spaces, " ");
	if (s == SLOPE_TOP)
		ft_putstr_fd("┌─ ", 2);
	else if (s == SLOPE_NULL)
		ft_putstr_fd("*─ ", 2);
	else if (s == SLOPE_BOT)
		ft_putstr_fd("└─ ", 2);
	c_yellow();
	ft_dprintf(2, "%s", root->andor->content);
	c_reset();
	btree_show_2d___(root->right, spaces + 5, SLOPE_BOT);
}

static void	___2d_pipeline(t_btree *root, int spaces, t_slope s)
{
	t_token	*t;

	t = root->pipeline;
	ft_dprintf(2, "\n");
	ft_putx_fd(2, spaces, " ");
	if (s == SLOPE_TOP)
		ft_dprintf(2, "┌─");
	else if (s == SLOPE_BOT)
		ft_dprintf(2, "└─");
	ft_dprintf(2, "[");
	c_yellow();
	while (t)
	{
		if (t->name == T_PARENTHESIS)
			ft_dprintf(2, " ");
		else
			ft_dprintf(2, "%s", t->content);
		t = t->next;
	}
	c_reset();
	ft_dprintf(2, "]\n");
}

static void	btree_show_2d___(t_btree *root, int spaces, t_slope slope)
{
	if (!root)
		return ;
	if (root->andor)
		___2d_andor(root, spaces, slope);
	if (root->pipeline)
		___2d_pipeline(root, spaces, slope);
}

void	btree_show_2d(t_btree *root)
{
	c_magenta();
	ft_dprintf(2, "\nTREE");
	c_reset();
	btree_show_2d___(root, 0, SLOPE_NULL);
	ft_putnl_fd(2);
}

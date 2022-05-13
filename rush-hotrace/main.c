/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:30:56 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/12/12 22:39:12 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_ulong	gethash(char *key)
{
	t_ulong	hash;

	hash = 881;
	while (*key)
	{
		hash *= 883;
		hash += *key;
		key++;
	}
	return (hash % M);
}

int	parse_dict(t_list *dict)
{
	t_ulong	hash;
	char	*key;
	char	*val;

	while (1)
	{
		if (get_next_line(0, &key) < 0)
			return (exit_error("gnl error", dict, key, 0));
		if (!*key)
		{
			free(key);
			return (1);
		}
		if (get_next_line(0, &val) < 0)
			return (exit_error("gnl error", dict, key, val));
		hash = gethash(key);
		if (dict[hash].key)
		{
			if (!add_front(&dict[hash].next, new_list(key, val), dict))
				return (0);
		}
		else
			add_key(dict + hash, key, val);
	}
	return (1);
}

void	search_collision(t_list *l, char *key, t_buf *buf)
{
	if (!l->next)
	{
		if (!ft_strcmp(key, l->key))
			found(buf, l->val);
		else
			notfound(buf, key, ft_strlen(key));
	}
	else
	{
		while (l)
		{
			if (!ft_strcmp(key, l->key))
			{
				found(buf, l->val);
				return ;
			}
			l = l->next;
		}
		notfound(buf, key, ft_strlen(key));
	}
}

int	search_key(t_list *dict)
{
	char	*key;
	int		ret;
	t_buf	buf;
	t_ulong	hash;

	buf.len = 0;
	ret = get_next_line(0, &key);
	while (ret > 0)
	{
		hash = gethash(key);
		if (dict[hash].key)
			search_collision(&dict[hash], key, &buf);
		else
			notfound(&buf, key, ft_strlen(key));
		free(key);
		ret = get_next_line(0, &key);
	}
	free(key);
	if (ret == -1)
		return (exit_error("gnl error", dict, 0, 0));
	write(1, buf.buf, buf.len);
	return (1);
}

int	main(void)
{
	t_list	*dict;

	dict = (t_list *)malloc(M * sizeof(t_list));
	if (!dict)
		return (exit_error("dic malloc error", 0, 0, 0));
	ft_bzero(dict, M * sizeof(t_list));
	if (!parse_dict(dict))
		return (1);
	if (!search_key(dict))
		return (1);
	free_dict(dict);
	get_next_line(0, 0);
	return (0);
}

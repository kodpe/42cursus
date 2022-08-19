/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 00:36:12 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 19:10:58 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	isvar(char *str)
{
	if (str[0] == '$' && (ft_isalnum(str[1]) || str[1] == '_'))
		return (1);
	if (str[0] == '$' && str[1] == '?')
		return (1);
	if (str[0] == '$' && str[1] == '$')
		return (1);
	return (0);
}

char	*expander(char *str, t_env *env)
{
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (isvar(&str[i]))
		{
			i++;
			str = env_expandone(str, &i, env);
			if (!str)
				return (NULL);
		}
		else
			i++;
	}
	return (str);
}

t_token	*env_expander(t_token *pipeline, t_env *env)
{
	t_token	*new;
	t_token	*t;

	t = pipeline;
	while (t)
	{
		if (t->name == T_REDIR && !strncmp(t->content, "<<", 2))
		{
			if (env_expander_here_doc(&t))
				return (NULL);
		}
		if (!t)
			break ;
		if (detect_last_dollar(t))
			return (NULL);
		if (t->name == T_WORD)
			t->content = expander(t->content, env);
		else if (t->name == T_ENTREQUOTE && t->content[0] == '"')
			t->content = expander(t->content, env);
		if (!t->content)
			return (NULL);
		t = t->next;
	}
	new = env_split_token(pipeline, T_WORD, ' ');
	return (new);
}

/*
int main(int ac, char **av, char **envp)
{
	t_env	*env;

	env = env_init(envp);
	expand(env, "");
	expand(env, "''");
	expand(env, "\"\"");
	expand(env, "$");
	expand(env, "begin$$end");
	expand(env, "a$$b");
	expand(env, "a$$");
	expand(env, "$$b");
	expand(env, "$$");
	expand(env, "$$$a$USER");
	expand(env, "$$$$USER");
	expand(env, " $$");
	expand(env, "  $$ ");
	expand(env, "jfewjgg--$$--djiowfj");
	expand(env, "$$bonjour$oui $$non");
	expand(env, "$?");
	expand(env, "$$USEROIJOI$ $$JOIJOIJOIJ");
	expand(env, " $?");
	expand(env, " $?$$");
	expand(env, "  $?$?$?");
	expand(env, "$ $");
	expand(env, "$ a $-$");
	expand(env, "       $a $b ");
	expand(env, " $ $");
	expand(env, "  $ $ ");
	expand(env, "  $a $b ");
	expand(env, " $a $b");
	expand(env, "$a$b    ");
	expand(env, " $abc $def");
	expand(env, "$abc$def $$   ");
	expand(env, "$  $a $ab $abc $");
	expand(env, "$ $$ $? $$$ $?$ $$$$ $a$b$c $abc");
	expand(env, "$?$?$? $$$$$$$$$OK $OK $1$`$-$=$98");
	expand(env, "$USER");
	expand(env, "LS_COLOR");
	expand(env, "$$$$$$$$$$LS_COLOR$$$$$$$$$LS_COLORO");
	expand(env, "$$$$$$$$$$LS_COLOR$$$$$$$$$LS_COLO");
	expand(env, "$$$$$$$$$$LS_COLOR$$$$$$$$LS_COLOR");
	expand(env, "$$$$$$$$$$LS_COLOR$$$$$$$$LS_COLORS");
	expand(env, "$$$$$$$$$$LS_COLOR$$$LSCOLORS");
	expand(env, "$YOOOOOOOOOOO$LANG $LOGNAME $USER $$$?$LESS $$$$$SHLVL");
	expand(env, "U");
	expand(env, "$");
	env_destroy(&env);
	(void)ac;
	(void)av;
}
*/

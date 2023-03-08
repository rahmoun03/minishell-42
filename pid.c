/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:33:53 by arahmoun          #+#    #+#             */
/*   Updated: 2023/03/06 13:02:40 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_token(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] == 34 || str[i] == 39 || str[i] == '$')
		{
			if(str[i] == 34)
			{
				i++;
				while (str[i] && str[i] != '$' && str[i] != 34)
					i++;
			}
			if (str[i] == '$' && str[i + 1] == '$')
			{
				// printf("in\n");
				return 1;
			}
			if (str[i] == '$' && str[i + 1] != '$')
				i++;
			if (str[i] == 39)
			{
				i++;
				while (str[i] && str[i] != 39)
					i++;
				i++;
			}
		}
		else
			i++;
	}
	// printf("not found\n");
	return 0;
}
char    *handle_pid(char *str, char *pid)
{
	int i;
	int slen;
	int len;
	char *re;

	i = 0;
	slen = 0;
	len = (ft_strlen(str) + ft_strlen(pid)) - 2 ;
	re = (char *)malloc(len + 1);
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39 || str[i] == '$')
		{
			if (str[i] == 34)
			{
				re[slen++] = str[i++];
				while (str[i] && str[i] != 34 && str[i] != '$')
					re[slen++] = str[i++];
			}
			if (str[i] == '$' && str[i + 1] == '$')
			{
				len = 0;
				while (pid[len])
				{
					re[slen] = pid[len];
					slen++;
					len++;
				}
				i += 2;
				while (str[i])
					re[slen++] = str[i++];
				re[slen] = '\0';
				free(str);
				return re;
			}
			if (str[i] == '$' && str[i + 1] != '$')
				re[slen++] = str[i++];
			if (str[i] == 39)
			{
				re[slen++] = str[i++];
				while (str[i] && str[i] != 39)
					re[slen++] = str[i++];
				re[slen++] = str[i++];
			}
		}
		else
			re[slen++] = str[i++];
	}
	re[slen] = '\0';
	free(str);
	return re;
}

void    check_pid(t_all *lexer, char **env)
{
	int i;
	t_all *tmp;

	tmp = lexer;
	while (tmp)
	{
		i = 0;
		while (tmp->cmd[i])
		{
			expand_var(lexer, env);
			if(check_token(tmp->cmd[i]))
			{
				tmp->cmd[i] = handle_pid(tmp->cmd[i], ft_itoa(lexer->pid));
				i = -1;
			}
			i++;
		}
		tmp = tmp->next;
	}
	
}
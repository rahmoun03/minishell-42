/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:37:49 by moazzedd          #+#    #+#             */
/*   Updated: 2023/03/02 12:38:05 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	double_free(char **str)
{
	int i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}
int ft_is_char(char c)
{
	if (c == ' ' || c == '\t' || c == '\0' || c == '|')
		return 1;
	return 0;
}

int ft_len(char **str, int i, int j)
{
	int len = 0;
	while (!ft_is_char(str[i][j]))
	{
		len++;
		j++;
	}
	return len;
}

void	skip_spaces(char *str, int *i)
{
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		(*i)++;
}
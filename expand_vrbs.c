/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vrbs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:36:06 by arahmoun          #+#    #+#             */
/*   Updated: 2023/03/04 18:04:56 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

char *cpy_var(char *s, char *str)
{
    char *dst;
    int i = 0;
    int a = 0;
    int slen = 0;
    int len = ft_strlen(s);

    while (str[i] != '=')
        i++;
    a = i + 1;
    while (s[slen] != '$')
    {
        if(s[slen] == 34)
        {
            slen++;
            while (s[slen] && s[slen] != 34 && s[slen] != '$')
                slen++;
        }
        if (s[slen] == '$')
            break;
        if(s[slen] == 39)
        {
            slen++;
            while (s[slen] && s[slen] != 39)
                slen++;
        }
        slen++;
    }
    slen += a;
    len -= i;
    while (str[++i])
        len++;
    dst = (char *)malloc(len);
    len = 0;
    while (s[len] != '$')
    {
        if(s[len] == 34)
        {
            dst[len] = s[len];
            len++;
            while (s[len] && s[len] != 34 && s[len] != '$')
            {
                dst[len] = s[len];
                len++;
            }
        }
        if (s[len] == '$')
            break;
        if(s[len] == 39)
        {
            dst[len] = s[len];
            len++;
            while (s[len] && s[len] != 39)
            {
                dst[len] = s[len];
                len++;
            }
        }
        if (s[len] != '$')
        {
            dst[len] = s[len];
            len++;
        }
    }
    while (str[a])
    {
        dst[len] = str[a];
        len++;
        a++;
    }
    while (s[slen])
        dst[len++] = s[slen++];
    dst[len] = '\0';
    free(s);
    return dst;
}

int	ft_strcmp(char *s1, char *s2)
{
	int			    i;
    int             a;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
    while (s22[i] && s22[i] != '$')
    {
        if(s22[i] == 34)
        {
            i++;
            while (s22[i] && s22[i] != 34 && s22[i] != '$')
                i++;
        }
        if (s22[i] == '$')
            break;
        if(s22[i] == 39)
        {
            i++;
            while (s22[i] && s22[i] != 39)
                i++;
        }
        i++;
    }
    a = 0;
	while (s11[a] != '=' && s22[i] && s11[a] == s22[i + 1])
    {
        a++;
		i++;
    }
    if (s11[a] == '=' && (s11[a - 1] == s22[i]) && (s22[i + 1] == '\0' || !ft_isalnum(s22[i + 1])))
		return (0);
    return (1);
}

char    *fix_var(char *str, char **envp)
{
    int i;

    i = 0;
    
    while (envp[i])
    {
        if(ft_strcmp(envp[i], str) == 0)
        {
            str = cpy_var(str, envp[i]);
            i = 0;
        }
        i++;
    }
    return str;
}

void    expand_var(t_all *lexer, char **envp)
{
    t_var var;

    var.temp = lexer;
    while (var.temp)
    {
        var.i = 0;
        while (var.temp->cmd[var.i])
        {
            var.temp->cmd[var.i] = fix_var(var.temp->cmd[var.i], envp);
            var.i++;
        }
        var.temp = var.temp->next;
    }
    
}
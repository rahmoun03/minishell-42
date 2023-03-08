/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:33:28 by arahmoun          #+#    #+#             */
/*   Updated: 2023/03/08 14:14:05 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define DEF "\033[0m"

typedef struct s_redir
{
    int				type;
    char			**args;
	struct s_redir	*next;
}					t_redir;

typedef struct s_all
{
	int				pid;
	char			*text;
	char			**cmd;
	char			**command;
	t_redir			*rdr;
	struct s_all	*next;
}					t_all;

typedef struct s_var
{
	int		i;
	int		j;
	int		x;
	t_all	*temp;
}			t_var;

//      error
void	error_arg(void);
void    ft_error(void);

// linked list
t_all	*ft_lstnew(void);
void	ft_lstadd_back(t_all **lst, t_all *new);

//      tools
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char 	**ft_ddup(char **str);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
void	*ft_calloc(int count, int size);

// parser functions
char	**ft_split(char const *s, char *c);
char    *sp_split(char *str);
void    remove_dq(t_all *);
void    expand_var(t_all *lexer, char **envp);
void    check_pid(t_all *lexer, char **env);

// executer functions
char	*get_path();
void    ft_exec(t_all *lexer);
# endif
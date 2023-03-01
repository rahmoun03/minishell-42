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
    char			*file;

}					t_redir;

typedef struct s_all
{
	char			*text;
	char			**cmd;
	char			**command;
	t_redir			*rdr;
	struct s_all	*next;
}					t_all;

//      error
void	error_arg(void);
void    ft_error(void);
// linked list

t_all	*ft_lstnew(void);
void	ft_lstadd_back(t_all **lst, t_all *new);

//      tools
char	*ft_strdup(const char *s1);
char 	**ft_ddup(char **str);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char *c);
char    *sp_split(char *str);

# endif
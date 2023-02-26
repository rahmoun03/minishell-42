#include "minishell.h"

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

void	lexer_text(t_all *lexer, char **envp)
{
	(void)envp;
	int i;
	int j;
	int len;
	t_all *tmp;

	len = 0;
	tmp = lexer;
	i = 0;
	j = 0;
	lexer->command = ft_split(lexer->text, '|');
	while (lexer->command[i])
	{
		tmp->cmd = ft_split(lexer->command[i], ' ');
		i++;
		if (lexer->command[i])
		{
			ft_lstadd_back(&lexer, ft_lstnew());
			tmp = tmp->next;
		}
	}
}

void	init_lexer(t_all *lexer, char **env)
{
	t_all *tmp = lexer;
	int i = 0;

	lexer->text = readline(READLINE_MSG);
	add_history(lexer->text);
	lexer_text(lexer, env);

	while(tmp != NULL)
	{
		i = 0;
		printf("-=-=-=-=-=-=-=-=-=-=-=-");
		while (tmp->cmd[i])
		{
			printf("\n%d -> command=%s%%\n", i + 1, tmp->cmd[i]);
			i++;
		}
		tmp = tmp->next;
	}
}

int main(int ac, char **av, char **envp)
{
	char	**envp_cpy;
	t_all 	*lexer;
	
	if (ac != 1 || av[1])
		error_arg();
	lexer = (t_all *)malloc(sizeof(t_all));
	envp_cpy = ft_ddup(envp);
	lexer->next = NULL;

	while (1)
	{
		init_lexer(lexer, envp);

	/*-------- executor ------*/
		system(lexer->text);
	}
}

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

void	lexer_text(t_all *lexer, char **envp)
{
	(void)envp;
	int i;
	t_all *tmp;

	tmp = lexer;
	i = 0;
	lexer->command = ft_split(lexer->text, "|");
	free(lexer->text);
	while (lexer->command[i])
	{
		lexer->command[i] = sp_split(lexer->command[i]);
		tmp->cmd = ft_split(lexer->command[i], " ");
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
	lexer = ft_lstnew();
	t_all *tmp ;
	int i = 0;

	tmp = NULL;
	lexer->text = readline(READLINE_MSG);
	if (ft_strlen(lexer->text) != 0)
	{
		add_history(lexer->text);
		lexer_text(lexer, env);
		remove_dq(lexer);
		tmp = lexer;
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
		/*----- in the end of code -----*/
		double_free(lexer->command);
		double_free(lexer->cmd);
		free(lexer);
	}
}

int main(int ac, char **av, char **envp)
{
	t_all 	*lexer;
	
	lexer = NULL;
	if (ac != 1 || av[1])
		error_arg();

	while (1)
	{
		init_lexer(lexer, envp);

	/*-------- executor ------*/
		// system(lexer->text);
	}
}

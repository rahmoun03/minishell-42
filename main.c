#include "minishell.h"

int ft_is_char(char c)
{
	if (c == ' ' || c == '\t' || c == 34 || c == 39
		|| c == '|' || c == '>' || c == '<' || c == '=')
		return 1;
	return 0;
}

void	skip_spaces(t_all *lexer, int *i)
{
	while (lexer-> text[*i] == ' ' || lexer-> text[*i] == '\t')
		(*i)++;
}

void	lexer_text(t_all *lexer)
{
	int i;
	int j;

	i = 0;
	while (lexer->text[i])
	{
		printf("aa\n");
		skip_spaces(lexer, &i);
		j = 0;
		while (!ft_is_char(lexer->text[i]))
			lexer->command[j++] = lexer->text[i++];
		skip_spaces(lexer, &i);
		j = 0;
	}
}

void	init_lexer(t_all *lexer)
{
	lexer->text = readline(READLINE_MSG);
	add_history(lexer->text);
	lexer_text(lexer);
	printf("text = %s \n", lexer->text);
	free(lexer->text);
}

int main(int ac, char **av, char **envp)
{
	char	**envp_cpy;
	t_all *lexer;
	
	if (ac != 1 || av[1])
		error_arg();
	lexer = (t_all *)malloc(sizeof(t_all));
	envp_cpy = ft_ddup(envp);

	while (1)
	{
		init_lexer(lexer);

	/*-------- executor ------*/
		system(lexer->text);
	}
}


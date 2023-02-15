#include "lexer.h"

void	error_arg(void)
{
	printf("%splease dont use the arguments%s\n", RED, DEF);
	exit(1);
}

void    ft_error(void)
{
    printf("syntax error \n");
    exit(1);
}
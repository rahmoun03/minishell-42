/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:41:38 by moazzedd          #+#    #+#             */
/*   Updated: 2023/03/03 21:17:43 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void    ft_exec(t_all *lexer)
{
    char **args;
    pid_t pid;

    pid = fork();

    // char **arg[];
    int i = 0;
    // printf("---pid %d\n",pid);
        if (pid == 0)
        {
            args = lexer->cmd;
            while (lexer)
            {
                printf("her\n");
                while (args[i])
                {
                    execvp(args[i], args);
                    printf("|||||||||||||\n");
                    i++;
                }
                lexer = lexer->next;
                args = lexer->cmd;
                i = 0;
            }
            
        }
        else if (pid > 0)
            waitpid(pid, &i, 0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:41:38 by moazzedd          #+#    #+#             */
/*   Updated: 2023/03/09 18:42:29 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	one_exec(t_all *lexer)
{
    int i;
	
	i = 0;
	while (lexer)
	{
		while (lexer->cmd[i])
		{
			execvp(lexer->cmd[i], lexer->cmd);
			i++;
		}
		i = 0;
		lexer = lexer->next;
	}
}

void	two_exec(t_all *lexer)
{
	int pipefd[2];
	pid_t pid = fork();
	if (pid == 0)
	{
    	close(pipefd[0]);
    	dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
        execvp(lexer->cmd[0], lexer->cmd);
    }
	else
	{
        close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
        waitpid(pid, NULL, 0);
        execvp(lexer->next->cmd[0], 	lexer->next->cmd);
    }
}
void    ft_exec(t_all *lexer)
{
	int pipefd[2];
	pipe(pipefd);

    pid_t pid = fork();
	if (lexer->next == NULL)
		one_exec(lexer);
	printf("------------> %d\n",pid);
    if (pid == -1)
        perror("fork");
	else
	{
		while (lexer)
		{
    		if (pid == 0)
			{
    			close(pipefd[0]);
     			dup2(pipefd[1], STDOUT_FILENO);
				close(pipefd[1]);
    		    execvp(lexer->cmd[0], lexer->cmd);
    		}
			else
			{
    		    close(pipefd[1]);
				dup2(pipefd[0], STDIN_FILENO);
				close(pipefd[0]);
    		    waitpid(pid, NULL, 0);
    		    execvp(lexer->next->cmd[0], lexer->next->cmd);
    		}
			lexer = lexer->next;
		}
	}


    // return 0;
}
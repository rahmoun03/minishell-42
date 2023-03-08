/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:41:38 by moazzedd          #+#    #+#             */
/*   Updated: 2023/03/08 16:16:54 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void    ft_exec(t_all *lexer)
{
    // pid_t pid;
//     int i;
	
// 	i = 0;
// 	while (lexer)
// 	{
//     	pid = fork();
// 		if (pid == 0)
// 		{
// 			while (lexer->cmd[i])
// 			{
// 				execvp(lexer->cmd[i], lexer->cmd);
// 				i++;
// 			}
// 		}
// 		else
// 			waitpid(pid, &i, i);
// 		i = 0;
// 		lexer = lexer->next;
// 	}
// }

  int pipefd[2];
    pipe(pipefd);

    pid_t pid = fork();
	
    if (pid == -1)
        perror("fork");
	if (lexer->next == NULL)
		execvp(lexer->cmd[0], lexer->cmd);
	else
	{
    	if (pid == 0)
		{
    	    // child process
    	    close(pipefd[0]); // close unused read end of the pipe
     	   dup2(pipefd[1], STDOUT_FILENO); // 	redirect stdout to write end of the pipe
    	    close(pipefd[1]); // close write end of the pipe
	
    	    execvp(lexer->cmd[0], lexer->cmd);
    	    // perror("execvp");
    	    // return 1;
    	}
		else
		{
    	    // parent process
    	    close(pipefd[1]); // close unused write 	end of the pipe
    	    dup2(pipefd[0], STDIN_FILENO); // redirect 	stdin to read end of the pipe
    	    close(pipefd[0]); // close read end of the 	pipe
	
    	    waitpid(pid, NULL, 0); // wait for child 	process to finish
	
    	    execvp(lexer->next->cmd[0], 	lexer->next->cmd);
    	    // perror("execvp");
    	}
	}


    // return 0;
}
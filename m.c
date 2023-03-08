// #include <stdio.h>

// int main() {
//     FILE *ls_pipe, *grep_pipe;
//     char buffer[1024];
    
//     // open pipes to commands
//     ls_pipe = popen("ls -l", "r");
//     if (!ls_pipe) {
//         printf("Error: popen failed.\n");
//         return -1;
//     }
//     grep_pipe = popen("grep main", "w");
//     if (!grep_pipe) {
//         printf("Error: popen failed.\n");
//         return -1;
//     }
    
//     // read from ls pipe and write to grep pipe
//     while (fgets(buffer, sizeof(buffer), ls_pipe)) {
//         fputs(buffer, grep_pipe);
//     }
    
//     // close pipes
//     pclose(ls_pipe);
//     pclose(grep_pipe);
    
//     return 0;
// }

#include <stdio.h>
#include <unistd.h>

int main() {
    char *ls_command[] = {"ls", "-l", NULL};
    char *grep_command[] = {"grep", "file.txt", NULL};

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // child process - redirect stdout to pipe write end
        close(pipefd[0]); // close unused read end
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]); // close pipe write end
        execvp(ls_command[0], ls_command);
        perror("execvp failed");
        return 1;
    } else {
        // parent process - redirect stdin to pipe read end
        close(pipefd[1]); // close unused write end
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]); // close pipe read end
        execvp(grep_command[0], grep_command);
        perror("execvp failed");
        return 1;
    }
}

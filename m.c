#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *path = getenv("PATH");
    char *args[] = {"echo", "Hello, world!", NULL};
    char *envp[] = {NULL};

    if (execve(path, args, envp) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
    }

    return 0;
}

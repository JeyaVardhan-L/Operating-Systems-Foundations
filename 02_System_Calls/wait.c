#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        printf("Child Process\n");
    } else {
        wait(NULL);
        printf("Parent after child finishes\n");
    }

    return 0;
}
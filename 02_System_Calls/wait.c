#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        wait(NULL);
        printf("Parent after child finishes\n");
    } else {
        printf("Child Process\n");
    }

    return 0;
}
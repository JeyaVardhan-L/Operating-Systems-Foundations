#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec\n");

    execl("/bin/ls", "ls", NULL);

    printf("After exec\n"); // This will not execute

    return 0;
}
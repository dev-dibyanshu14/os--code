#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Process 1 (p1)
    printf("Process 1 (p1) - PID: %d, Parent PID: %d\n", getpid(), getppid());

    // Fork to create Process 2 (p2)
    pid_t pid2 = fork();

    if (pid2 == -1) {
        perror("fork");
        exit(1);
    }

    if (pid2 == 0) {
       
        printf("Process 2 (p2) - PID: %d, Parent PID: %d\n", getpid(), getppid());

       
        pid_t pid3 = fork();

        if (pid3 == -1) {
            perror("fork");
            exit(1);
        }

        if (pid3 == 0) {
           
            printf("Process 3 (p3) - PID: %d, Parent PID: %d\n", getpid(), getppid());
        }
    }
}

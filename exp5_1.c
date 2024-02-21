#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. n should be greater than 0.\n");
        exit(1);
    }

    for (int i = 1; i <= n; i++) {
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            exit(1);
        }

        if (child_pid == 0) {
            
            printf("Child process %d with PID %d\n", i, getpid());
            break; 
        } else {

            wait(NULL); 
        }
    }
}

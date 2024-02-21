#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
 
    printf("P1 (PID: %d)\n", getpid());


    pid_t pid2 = fork();
    if (pid2 == 0) {
        printf("P2 (PID: %d) - Parent: P1 (PID: %d)\n", getpid(), getppid());

     
        pid_t pid3 = fork();
        if (pid3 == 0) {
            printf("P3 (PID: %d) - Parent: P2 (PID: %d)\n", getpid(), getppid());

            
            pid_t pid4 = fork();
            if (pid4 == 0) {
                printf("P4 (PID: %d) - Parent: P3 (PID: %d)\n", getpid(), getppid());
                sleep(5);  
                printf("P4 (PID: %d) - Parent: P1 (PID: %d)\n", getpid(), getppid());
            }
        }
    }

  
    pid_t pid5 = fork();
    if (pid5 == 0) {
        printf("P5 (PID: %d) - Parent: P1 (PID: %d)\n", getpid(), getppid());

     
        pid_t pid6 = fork();
        if (pid6 == 0) {
            printf("P6 (PID: %d) - Parent: P5 (PID: %d)\n", getpid(), getppid());

            pid_t pid7 = fork();
            if (pid7 == 0) {
                printf("P7 (PID: %d) - Parent: P6 (PID: %d)\n", getpid(), getppid());
                return 0;
            }
        }
    }


    wait(NULL);

    return 0;
}
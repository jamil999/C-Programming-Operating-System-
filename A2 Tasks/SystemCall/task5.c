#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_process, grandchild1_process,grandchild2_process,grandchild3_process;
    child_process = fork();

    if (child_process == 0) {
        printf("2. Child process ID: %d\n", getpid());
        grandchild1_process = fork();
        if (grandchild1_process == 0) {
            printf("3. Grand Child process ID: %d\n", getpid());
        } else if (grandchild1_process > 0) {
            grandchild2_process = fork();
            if (grandchild2_process == 0) {
                printf("4. Grand Child process ID: %d\n", getpid());
            } else if (grandchild2_process > 0) {
                grandchild3_process = fork();
                if (grandchild3_process == 0) {
                    printf("5. Grand Child process ID: %d\n", getpid());
                } else if (grandchild3_process > 0) {
                    wait(NULL);
                }
            } 
        }
    } else if (child_process > 0) {
        printf("1. Parent process ID: %d\n", getpid());
    }

    return 0;
}

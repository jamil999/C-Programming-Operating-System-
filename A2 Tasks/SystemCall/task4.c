#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    pid_t child_process;
    child_process = fork();
    if(child_process == 0){
        argv[0] = "./sort";
        execv(argv[0], argv);
    }
    else{
        wait(NULL);
        argv[0] = "./oddeven";
        execv(argv[0], argv);
}
}

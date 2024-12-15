#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
	//start of parent
	pid_t pid_child_process, pid_grandchild_process;
	
	pid_child_process = fork();
	
	if (pid_child_process == 0){
		pid_grandchild_process = fork();
		
		if (pid_grandchild_process == 0){
			printf("I am grandchild\n");
		}
		else{
			wait(NULL);
			printf("I am child\n");
		}
	}
	else{
		wait(NULL);
		printf("I am parent\n");
	}	
}

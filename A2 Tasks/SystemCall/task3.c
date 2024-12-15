#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

int main() {
	int current_process_num;
	current_process_num = 1;
	int a,b,c;
	
	a = fork();
	b = fork();
	c = fork();
	current_process_num = current_process_num + 3;
	
	if (a == 0){
		int check_pid = getpid();
		if (check_pid % 2 != 0 ){
			fork();
			current_process_num = current_process_num + 1;
			
			
		}
	}
	
	else if (b == 0){
		int check_pid = getpid();
		if (check_pid % 2 != 0){
			fork();
			current_process_num = current_process_num + 1;
	}
	}
	else if (c == 0){
		int check_pid = getpid();
		if (check_pid % 2 != 0 ){
			fork();
			current_process_num = current_process_num + 1;
		}
	}
	else{
	printf("Total processes that have been created: %d\n",current_process_num);
	}
	return 0;	
			
}

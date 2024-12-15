#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>


struct shared{
  char sel[100];
  int b;
};

int main(){
  struct shared *shared1;
  int sm_id=shmget((key_t)199,1024,0666|IPC_CREAT);
  shared1=shmat(sm_id,NULL,0);
  
  int fd[2];
  int p=pipe(fd);
  
  pid_t opr_child;
  
      printf("Provide Your Input from Given Options:\n1. Type a to Add Money\n2. Type w to Withdraw Money \n3. Type c to Check Balance\n");
    scanf("%s",shared1->sel);
    shared1->b = 1000;
    
    printf("Your selection: %s\n",shared1->sel);
  
  
  opr_child = fork();
  if (opr_child == 0){
    close(fd[0]);
    if (strcmp(shared1->sel,"a") == 0){
      int add;
      printf("Enter amount to be added: \n");
      scanf("%d",&add);
      
      if (add > 0){
        shared1->b += add;
        printf("Balance added successfully\nUpdated balance after addition:\n%d\n",shared1->b);
        
      }
      else{
      printf("Adding failed, Invalid amount\n");
      } 
    }
    else if (strcmp(shared1->sel,"w") == 0){
      int sub;
      printf("Enter amount to be withdrawn: \n");
      scanf("%d",&sub);
      
      if (sub > 0 && sub < shared1->b){
        shared1->b -= sub;
        printf("Balance withdrawn successfully\nUpdated balance after withdrawal:\n%d\n",shared1->b);
        
      }
      else{
      printf("Withdrawal failed, Invalid amount\n");
      }
    }
    
    else if (strcmp(shared1->sel,"c") == 0){
    printf("Your current balance is: \n%d\n",shared1->b); 
    }
    else{
    printf("Invalid selection \n");
    }
    write(fd[1], "Thank you for using", sizeof("Thank you for using"));
    close(fd[1]);
    
    }
  else{
  
    wait(NULL);
    
    close(fd[1]);
    char buff[200];
    read(fd[0], buff, sizeof(buff));
    
    
    printf("%s\n",buff);
    close(fd[0]);
    shmctl(sm_id, IPC_RMID, NULL);
  }
  return 0; 
}

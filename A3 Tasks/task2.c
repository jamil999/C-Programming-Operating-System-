#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/wait.h>

struct msg{
long int type;
char txt[6];
};

int main(){
  char var1[100];
  printf("Please enter the workspace name: \n");
  scanf("%s",var1);
 
   if (strcmp(var1, "cse321") != 0) {
        printf("Invalid workspace name\n");
   }
     
   else{
     int msg_id=msgget((key_t)123,0666|IPC_CREAT);
     struct msg msg1;
     strcpy(msg1.txt,var1);
     msg1.type = 5;
     msgsnd(msg_id,(void *)&msg1,sizeof(msg1.txt),0);
     printf("Workspace name sent to otp generator from log in: %s\n", msg1.txt);
     
     int otpid = fork();
     
     if (otpid == 0){
     struct msg msg2;
     msgrcv(msg_id,(void *)&msg2,sizeof(msg2.txt),5,IPC_NOWAIT);
     printf("OTP generator received workspace name from log in: %s\n",msg2.txt);
       
      struct msg mail1;
      strcpy(mail1.txt ,"4321"); //As said to give a random value
      mail1.type = 6;

      struct msg login1;
      strcpy(login1.txt, "4321");
      login1.type = 7;
       
      
      msgsnd(msg_id,(void *)&login1,sizeof(login1.txt),0);
      printf("OTP sent to log in from OTP generator: %s\n", login1.txt);
       
      msgsnd(msg_id,(void *)&mail1,sizeof(mail1.txt),0);
      printf("OTP sent to mail from OTP generator: %s\n", mail1.txt);
      
      pid_t mailprocess = fork();
       if (mailprocess == 0){
      struct msg mailr;
      msgrcv(msg_id,(void *)&mailr,sizeof(mailr.txt),6,IPC_NOWAIT);
       printf("Mail received OTP from OTP generator: %s\n",mailr.txt);
       
       struct msg sendtologin;
        strcpy(sendtologin.txt, mailr.txt);
        sendtologin.type = 8;
       msgsnd(msg_id,(void *)&sendtologin,sizeof(sendtologin.txt),0);
       printf("OTP sent to log in from mail: %s\n",sendtologin.txt);
         
       }
       else{
         wait(NULL); //parent is otp
       }   
     }
     else{
       wait(NULL);
       
      struct msg fromotp;
      msgrcv(msg_id,(void *)&fromotp,sizeof(fromotp.txt),7,IPC_NOWAIT);
      printf("Log in received OTP from OTP generator: %s\n",fromotp.txt);
       
      struct msg fromail;
      msgrcv(msg_id,(void *)&fromail,sizeof(fromail.txt),8,IPC_NOWAIT); 
      printf("Log in received OTP from mail: %s\n",fromail.txt);

        if (strcmp(fromotp.txt, fromail.txt) == 0) {
            printf("OTP Verified\n");
        } else {
            printf("Incorrect\n");
        }
       
       msgctl(msg_id,IPC_RMID,0);
     }   
     
   }
   return 0;
}

/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
//Collaborated with Peirce Medy & Izu

bool trigger = false; 

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  trigger = true;
  alarm(1);
}

int main(int argc, char * argv[])
{
  for(;;){
    trigger = false;
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1);
  while(trigger == false);
  printf("Turing was right!\n");
  }
  return 0;
}

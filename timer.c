#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
//Collaborated with Pierce Medy & Izu 

bool trigger = false;
int counter = 0;
time_t start;
time_t end;


void handler(int signum){
  printf("Hello World!\n");
  trigger = true;
  alarm(1);
  counter += 1;
}

void time_handler(int second){
  end = time(NULL);
  int diff = (end - start);
  printf("Total time in seconds: %d\n", diff);
  printf("Total time in executed: %d\n", counter);
  exit(1);
}

int main(int argc, char * argv[]){
  start = time(NULL);
  signal(SIGALRM, time_handler); 
  for(;;){
    trigger = false;
    signal(SIGALRM, handler);
    alarm(1);
    while(trigger == false);
    printf("Turing was right!\n");
  }
  return 0;
}

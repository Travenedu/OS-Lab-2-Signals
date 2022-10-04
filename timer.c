#include <time.h>
#include <unistd.h>

time_t start_time;
time_t end_time;
time_t total;
int number_alarm = 0;

void handler(int signum){
  printf("Hello World!\n");
}


void handler(int sec){
  end_time = time(NULL);
  total = end_time - start_time;
  printf("\nNumber of alarms : &d \n, number_alarm");
  printf("The program was excuting for: %ld seconds \n", total);
  exit(1)
}

int main(int argc, char * argv[]){
  start_time = time(NULL;)
  signal(SIGALRM,handler);
  signal(SIGINT,handler_sigint);
  do{
    alarm(1);
    num_alarms +=1;
    sleep(1);
    print("Turning was right!\n");
  } while(1);

  return 0;
}

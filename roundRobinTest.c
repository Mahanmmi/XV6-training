#include "types.h"
// #include "defs.h"
#include "user.h"

void loop(){
    
}
int main(){
    enum schedulerMode schedulerMode = RR;
    changePolicy(schedulerMode);

    int pid = getpid();
    for(int i=0; i < 10 ; i++){
        if(pid != 0){
            pid = fork();
 
            // child process
            if(pid == 0){

                // loop();
                for(int i=1; i <= 1000; i++){
                    printf(1, "pid:%d , i:%d\n", getpid(), i);
                }
                
                struct time_data *td = malloc (sizeof (struct children));

                getTimes(td);

                printf(1, "pid:%d, tt: %d, wt: %d, bt: %d\n", getpid(), td->turn_around_time, td->waiting_time, td->cpu_burst_time);
            }
 
        }
    }


    /* wait for all child to terminate */
    while(wait() != -1) { 
    }

    exit();
    
    return 0;
}
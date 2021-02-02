#include "types.h"
// #include "defs.h"
#include "user.h"

void loop(){
    
}
int main(){
    enum schedulerMode schedulerMode = RR;
    changePolicy(schedulerMode);

    int pid = 1;
    for(int i=0; i < 10 ; i++){
        if(pid != 0){
            pid = fork();
 
            // child process
            if(pid == 0){

                // loop();
                for(int i=1; i <= 1000; i++){
                    printf(1, "pid:%d , i:%d\n", getpid(), i);
                }
                                
                struct time_data *td = malloc (sizeof (struct time_data));

                getTimes(td);
                free(td);
                printf(1, "pid:%d, tt: %d, wt: %d, bt: %d\n", getpid(), td->turn_around_time, td->waiting_time, td->cpu_burst_time);
            }
 
        }
    }

    /* wait for all child to terminate */
    while(wait() != -1) { 
    }

    if(pid != 0){
        struct time_data *parentTd = malloc (sizeof (struct time_data));
        getAverageTimes(parentTd);
        printf(1, "parentId:%d, tt: %d, wt: %d, bt: %d\n", getpid(), parentTd->turn_around_time, parentTd->waiting_time, parentTd->cpu_burst_time);
        free(parentTd);
    }

    exit();
    
    return 0;
}
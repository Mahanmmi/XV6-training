#include "types.h"
#include "stat.h"
#include "user.h"
#include "utils.h"
char *states[6] = {
    "UNSUED",
    "EMBRYO",
    "SLEEPING",
    "RUNNABLE",
    "RUNNING",
    "ZOMBIE"
};
void printProcessStates(struct ps_states ps){
    printf(1, ">>>mypid: %d\n", getpid());
    printf(1, "PID Priority State\n");
    for(int i=0; i<ps.count; i++){
        if(ps.systemPs[i].pid != 0)
            printf(1, "[%d] %d     %d     %s\n",getpid(), ps.systemPs[i].pid,ps.systemPs[i].priority,states[ps.systemPs[i].state]);
    }
}
int main(){
    enum schedulerMode schedulerMode = PRIORITY;
    changePolicy(schedulerMode);
    setPriority(getpid(), 1);

    struct ps_states ps;
    ps.systemPs = malloc(64*sizeof(struct ps));

    int pid = getpid();
    printf(1, ">>>> mypid: %d\n", pid);

    for(int i=0; i < 30; i++){
        if(pid != 0){
            pid = fork();
            if(pid == 0) {
                setPriority(getpid(), 6 - (i / 5) );
                for(int j = 0; j < 250; j++) {
                    printf(1, "child #%d: %d\n", i, j);
                }

                struct time_data *td = malloc (sizeof (struct time_data));
                getTimes(td);
                printf(1, "pid:%d, tt: %d, wt: %d, bt: %d\n", getpid(), td->turn_around_time, td->waiting_time, td->cpu_burst_time);
                free(td);
            }
        }
    }

    // if (pid != 0) { 
    //     setPriority(9, 5);
    //     getPsStates(&ps);
    //     printProcessStates(ps);

    //     setPriority(9, 1);
    //     getPsStates(&ps);
    //     printProcessStates(ps);

    //     setPriority(9, 50);
    //     getPsStates(&ps);
    //     printProcessStates(ps);
    // }
    // if(getpid() == 9){
    //     getPsStates(&ps);
    //     printProcessStates(ps);   
    // }
    free(ps.systemPs);
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
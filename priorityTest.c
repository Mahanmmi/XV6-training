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
    enum schedulerMode schedulerMode = RR;
    changePolicy(schedulerMode);

    struct ps_states ps;
    ps.systemPs = malloc(64*sizeof(struct ps));

    int pid = getpid();
    printf(1, ">>>> mypid: %d\n", pid);

    for(int i=0; i<10; i++){
        if(pid != 0){
            pid = fork();
        }
    }

    if (pid != 0) { 
        setPriority(9, 5);
        getPsStates(&ps);
        printProcessStates(ps);

        setPriority(9, 1);
        getPsStates(&ps);
        printProcessStates(ps);

        setPriority(9, 50);
        getPsStates(&ps);
        printProcessStates(ps);
    }
    if(getpid() == 9){
        getPsStates(&ps);
        printProcessStates(ps);   
    }
    free(ps.systemPs);
    /* wait for all child to terminate */
    while(wait() != -1) { 
    }

    exit();

    return 0;
}
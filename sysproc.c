#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getParentID(void)
{
  return getParentID();
}

int
sys_getChildren(void){

  struct children *ch;

  if(argptr(0, (void*)&ch, sizeof(*ch)) < 0)
    return -1;
  return getChildren(ch);
  
}

int sys_getTimes(void){
  struct time_data *td;

  if(argptr(0, (void*)&td, sizeof(*td)) < 0)
    return -1;
  return getTimes(td);
}

int sys_getAverageTimes(void){
  struct time_data *td;

  if(argptr(0, (void*)&td, sizeof(*td)) < 0)
    return -1;
  return getAverageTimes(td);
}


int
sys_getSyscallCounter(void){
  int syscallid;
  if(argint(0, &syscallid) < 0 || syscallid >= NSYSCALL) {
    return -1;
  };
  
  return getSyscallCounter(syscallid);
}

int 
sys_changePolicy(void){
  enum schedulerMode *schedulerMode;
  if(argptr(0, (void*)&schedulerMode, sizeof(*schedulerMode)) < 0){
    return -1;
  }
  return changePolicy(*schedulerMode);
}

int 
sys_setPriority(){
  int priority, pid;
  if(argint(0, &pid) <0) {
    return -1;
  }
  if(argint(1, &priority) <0) {
    return -1;
  }  
  if(priority > 6 || priority < 1)
    priority = 5;

  return setPriority(pid, priority);
}

int
sys_getPsStates(){
  struct ps_states *st;

  if(argptr(0, (void*)&st, sizeof(*st)) < 0)
    return -1;
  return getPsStates(st);

}

int 
sys_setQueue(){
  int queueID;
  if(argint(0, &queueID) <0) {
    return -1;
  }
  return setQueue(queueID);
}
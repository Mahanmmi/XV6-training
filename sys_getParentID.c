#include "types.h"
#include "stat.h"
#include "user.h"

void callDaddy(){
  printf(1, "This is %d and my parent is %d\n", getpid(), getParentID());
}

int main() {
  if(fork() != 0)
    wait();
  if(fork() != 0)
    wait();
  callDaddy();
  exit();
}
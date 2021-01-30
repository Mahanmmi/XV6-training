#include "types.h"
#include "stat.h"
#include "user.h"

int strtol(char *s){
  int ans = 0;
  for(int i = 0; s[i] != 0; i++){
    ans *= 10;
    ans += s[i] - '0';
  }
  return ans;
}

void whatIveDone(int scid) {
  int num = getSyscallCounter(scid);
  if(num != -1){
    printf(1, "Im %d and I called %d, %d times!\n", getpid(), scid, getSyscallCounter(scid));
  } else {
    printf(1, "Invalid system call id!\n");
  }
}

int main(int argc, char *argv[]) {
  int scid = strtol(argv[1]);

  if(fork() != 0)
    wait();
  if(fork() != 0)
    wait();
  
  whatIveDone(scid);
  exit();
}
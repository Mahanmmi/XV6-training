typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;

struct children
{
    int parentId;
    char *data;
};

struct time_data {
    int cpu_burst_time;
    int turn_around_time;
    int waiting_time;
};

//Scheduler modes
enum schedulerMode{
  XV6,
  RR,
  PRIORITY
};

struct ps{
  int pid;
  short state; 
  int priority;
};

struct ps_states{
  struct ps *systemPs; 
  int count;
};


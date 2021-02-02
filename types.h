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
  RR
};


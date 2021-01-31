#include "types.h"
#include "user.h"
#include "children.h"
#include "utils.h"

void findTheDamnKids(){
    struct children *ch = malloc (sizeof (struct children));
    ch->parentId = getpid();
    ch->data = "";

    printf(1,"parentId: %d\n", ch->parentId); 
    
    if( getChildren(ch) > -1){
        printf(1, ">> Children Ids: %s\n", ch->data);
    }else{
        printf(1, "Problem with finding kids!\n");
    }
}
int main (int argc, char *argv[]) {

    int childrenCount = 5;
    if(argc > 1){
        childrenCount = strtol(argv[1]);
    }

    int pid = 1;
    for(int i=0; i<childrenCount; i++){
        if(pid != 0){
            pid = fork();
        }
    }

    if (pid != 0) { 
        findTheDamnKids();
    }

    /* wait for all child to terminate */
    while(wait() != -1) { 
    }

    exit();
}
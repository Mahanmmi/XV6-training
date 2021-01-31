#include "types.h"
#include "user.h"
#include "children.h"

void findTheDamnKids(){
    int p0 = fork(); 
    int p1 = fork();
    int p2 = fork();

    if (p0 > 0 && p1 > 0 && p2 > 0) { 
        struct children *ch = malloc (sizeof (struct children));
        ch->parentId = getpid();
        ch->data = "";

        printf(1,"parentId: %d\n", ch->parentId); 
        
        if( getChildren(ch) > -1){
            printf(1, ">> Children Ids: %s\n", ch->data);
        }else{
            printf(1, "Problem with finding children!\n");
        }
    }

    /* wait for all child to terminate */
    while(wait() != -1) { 
    }

    exit();
}
int main (void) {
    findTheDamnKids();
}
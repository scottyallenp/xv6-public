#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"


void agingPriorityTest() {

    printf(1, "Testing starvation priority:");

    int pid = 0;
    int arrPriority[4] = {7, 20, 15, 29};
    int i = 0;
    
    for (i = 0; i < 4; i++) {

        pid = fork();
        if (pid == 0) {
            setPriority(arrPriority[i]);
            printf(1, "child with pid %d has a priority of %d before doing its work.", getpid(), getPriority());
            // work for loop maybe
            printf(1, "child with pid %d has a priority of %d after doing its work.", getpid(), getPriority());
        }

    }
    

}


int main(int argc, char* argv[]) {

    if (atoi(argv[1]) == 1) {
        agingPriorityTest();
    }

    return 0;
}
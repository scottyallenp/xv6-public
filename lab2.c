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

    printf(1, "Testing starvation priority:\n");

    int pid;
    int arrPriority[4] = {16, 26, 31, 7};
    int i = 0;
    int j = 0;
    int x = 0;
    printf(1, "Setting the parent priority to zero\n");
    setPriority(0);
    for (i = 0; i < 4; i++) {
        pid = fork();
        if (pid > 0) {
            continue;
        }
        else if (pid == 0) {
            setPriority(arrPriority[i]);
            printf(1, "child with pid %d has a priority of %d before doing its work.\n", getpid(), getPriority());
            for (j = 0; j < 100; j++) {
                    asm("nop");
            }
            printf(1, "child with pid %d has a priority of %d while doing its work.\n", getpid(), getPriority());
            printf(1, "child with pid %d with original priority %d finishes.\n", getpid(), arrPriority[i]);
            exit();
        }

    }
    if (pid > 0) {

        for ( x = 0; x < 4; x++) {
            wait(0);
        }

        printf(1, "This parent process should finish last\n");
    }

    exit();
    
}


int main(int argc, char* argv[]) {

    if (atoi(argv[1]) == 1) {
        agingPriorityTest();
    }

    return 0;
}
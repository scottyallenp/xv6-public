#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

void exitTest() {

    printf(1, "Testing exit\n");

    int pid = fork(); 
    int exitvar;
    int childpid;

    if (pid == 0) {
        printf(1, "This is the child with pid %d\n", pid);
        printf(1, "This child exits with status 1\n");
        exit(1);
    }
    else {
        childpid = wait(&exitvar);
        printf(1, "This is the parent, ");
        printf(1, "its child with pid: %d exits with status %d\n", childpid, exitvar);
    }

    exit(0);
    printf(1, "This will not execute!\n");

}

void waitTest() {

    printf(1, "Testing wait\n");

    int pid = fork(); 
    int exitvar;
    int childpid;

    if (pid == 0) {
        
    }
    else {
        childpid = wait(&exitvar);
        
    }

    exit(0);
    printf(1, "This will not execute!\n");


}

void waitpidTest() {

}

int main(int argc, char* argv[]) {

    if (atoi(argv[1]) == 1) {
        exitTest();
    }

    else if (atoi(argv[2]) == 2) {
        waitTest();
    }

    else if (atoi(argv[3]) == 3) {
        waitpidTest();
    }


    return 0;
}
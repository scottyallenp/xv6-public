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
        exitStatus(1);
    }
    else {
        childpid = wait(&exitvar);
        printf(1, "This is the parent, with pid %d, ", pid);
        printf(1, "its child with pid: %d exits with status %d\n", childpid, exitvar);
    }

    exitStatus(0);
    printf(1, "This will not execute!\n");

}

void waitTest() {

    printf(1, "Testing wait\n");

    int pid = fork();
    int exitvar;
    int parentpid;

    if (pid == 0) {
        printf(1, "This is the child with pid %d\n", pid);
        printf(1, "It will always print the first 3 numbers 1-3: ");
        printf(1, "1, 2, 3\n");
        printf(1, "The child with pid: %d exits with status %d\n", pid, exitvar);
    }
    else {
        parentpid = wait(&exitvar);
        printf(1, "This is the parent with pid %d\n", pid);
        printf(1, "It will always print the second 3 numbers 4-6: ");
        printf(1, "4, 5, 6\n");
        printf(1, "The parent with the child pid of %d exits with status %d\n", parentpid, exitvar);

    }

    exitStatus(0);
    printf(1, "This will not execute!\n");


}

void waitpidTest() {

    printf(1, "Testing waitpid\n");

    int pidarr[4] = {0, 0, 0, 0};
    int exitvar;
    int pid;
    int i = 0;

    for(i = 0; i < 4; i++) {
        pidarr[i] = fork();
        if (pidarr[i] == 0) { // only the child executed this code
            printf(1, "\nThis is the child with PID# %d and it exits with status %d\n", getpid(), i);
            exitStatus(i);
        }
    }

    sleep(4);  
    printf(1, "\nThis is the parent\n Waiting for child with PID# %d\n",pidarr[2]);
    pid = waitpid(pidarr[2], &exitvar, 0);
    printf(1, "Child# %d has exited with status %d\n",pid, exitvar);
    sleep(4); 
    printf(1, "\n This is the parent\n Waiting for child with PID# %d\n",pidarr[0]);
    pid = waitpid(pidarr[0], &exitvar, 0);
    printf(1, "Child# %d has exited with status %d\n",pid, exitvar);
    sleep(4);  
    printf(1, "\n This is the parent\n Waiting for child with PID# %d\n",pidarr[3]);
    pid = waitpid(pidarr[3], &exitvar, 0);
    printf(1, "Child# %d has exited with status %d\n",pid, exitvar);
    sleep(4);  
    printf(1, "\n This is the parent\n Waiting for child with PID# %d\n",pidarr[1]);
    pid = waitpid(pidarr[1], &exitvar, 0);
    printf(1, "Child# %d has exited with status %d\n",pid, exitvar);

    exitStatus(0);
    printf(1, "This will not execute!\n");

}

int main(int argc, char* argv[]) {

    if (atoi(argv[1]) == 1) {
        exitTest();
    }

    else if (atoi(argv[1]) == 2) {
        waitTest();
    }

    else if (atoi(argv[1]) == 3) {
        waitpidTest();
    }


    return 0;
}
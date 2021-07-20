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
        printf(1, "The parent with pid: %d exits with status %d\n", parentpid, exitvar);

    }

    exit(0);
    printf(1, "This will not execute!\n");


}

void waitpidTest() {

    printf(1, "Testing waitpid\n");

    int pid = fork();
    int exitvar;
    int parentpid;

    if (pid == 0) {
        printf(1, "This is the child with pid %d\n", pid);
        printf(1, "It will always print the first 3 letters a-c: ");
        printf(1, "a, b, c\n");
        printf(1, "The child with pid: %d exits with status %d\n", pid, exitvar);
    }
    else {
        parentpid = waitpid(pid, &exitvar, 0);
        printf(1, "This is the parent with pid %d\n", pid);
        printf(1, "It will always print the last 3 letters x-z: ");
        printf(1, "x, y, z\n");
        printf(1, "The parent with pid: %d exits with status %d\n", parentpid, exitvar);

    }

    exit(0);
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
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

    

}


int main(int argc, char* argv[]) {

    if (atoi(argv[1]) == 1) {
        agingPriorityTest();
    }

    return 0;
}
#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

void partOne() {

    int pointerOne = 0;

    printf(1, "Address of pointerOne: %p\n", &pointerOne);
}

void partTwo(int x) {

    if(x == 0) {
        return;
    }
    else {
        partTwo(x-1);
    }

}


int main(int argc, char* argv[]) {

    printf(1, "Testing lab 3 memory layout\n");

    if (atoi(argv[1]) == 1) {
        partOne();
    }

    if (atoi(argv[1]) == 2) {
        partTwo(300);
    }


    return 0;
}
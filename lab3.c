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

    printf(1, "Address of pointerOne: %d\n", &pointerOne);
}

void partTwo() {

    int pointerOne = 0;
    int pointerTwo = 0;
    int pointerThree = 0;

    printf(1, "Address of pointerOne: %d\n", &pointerOne);
    printf(1, "Address of pointerTwo: %d\n", &pointerTwo);
    printf(1, "Address of pointerThree: %d\n", &pointerThree);
}



int main(int argc, char* argv[]) {

    printf(1, "Testing lab 3 memory layout\n");

    if (atoi(argv[1]) == 1) {
        partOne();
    }

    if (atoi(argv[1]) == 2) {
        partTwo();
    }


    return 0;
}
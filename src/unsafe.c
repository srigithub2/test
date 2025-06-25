// src/unsafe.c
#include <stdio.h>
//test 1
int global;

int main(void) {
    global = 42;
    printf("%d\n", global);
    return 0;
}


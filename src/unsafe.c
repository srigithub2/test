// src/unsafe.c
#include <stdio.h>
//TEST TEST
int global;

int main(void) {
    global = 42;
    printf("%d\n", global);
    return 0;
}


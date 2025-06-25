// src/unsafe.c
#include <stdio.h>

int global;
//TEST
int main(void) {
    global = 42;
    printf("%d\n", global);
    return 0;
}


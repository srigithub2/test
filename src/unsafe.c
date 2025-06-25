// src/unsafe.c
#include <stdio.h>

int global;
//TEST232323
int main(void) {
    global = 42;
    printf("%d\n", global);
    return 0;
}


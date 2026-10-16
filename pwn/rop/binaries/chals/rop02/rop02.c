// gcc -g -O0 -ldl -no-pie -fno-stack-protector -no-pie rop02.c -o rop02
#include <stdio.h>
#include <stdlib.h>

#include "rop02.h"


void foo() {
    __asm__("pop %rdi; ret");
}

void zee() {
    __asm__("pop %rax; pop %rdx; ret");
}

void bar() {
    __asm__("pop %rsi; ret");
}

void door() {
    __asm__("syscall; ret");
}


void fun() {
    char buf[16];
    printf("Please don't take my flag.\n");
    printf("Just tell me your name: ");

    fgets(buf, 100, stdin);

    printf("Here is a hint: ");
    printf("/bin/sh");
    printf("\n");
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    fun();
    return 0;
}
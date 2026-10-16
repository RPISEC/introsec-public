// gcc -g -O0 -ldl -no-pie -fno-stack-protector -no-pie rop01.c -o rop01
#include <stdio.h>
#include <stdlib.h>

#include "rop01.h"

void win(int a, int b) {
    char flag[64];
    FILE *f = fopen("flag", "r");
    if (f == NULL) {
        printf("Flag file is missing.\n");
        exit(0);
    }
    fgets(flag, 64, f);
    if (a == 1 && b == 1337) puts(flag);
    exit(0);
}

void foo() {
    __asm__("pop %rdi; ret");
}

void zee() {
    __asm__("pop %rax; ret");
}

void bar() {
    __asm__("pop %rsi; pop %rdx; ret");
}


void fun() {
    char buf[16];
    printf("Please don't take my flag.\n");
    printf("Just tell me your name: ");
    fgets(buf, 100, stdin);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    fun();
    return 0;
}
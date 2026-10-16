// gcc -g -O0 -ldl -no-pie -fno-stack-protector -no-pie rop03.c -o rop03
#include <stdio.h>
#include <stdlib.h>

void fun() {
    char buf[16];
    printf("Please don't take my flag.\n");
    printf("Just tell me your name: ");

    fgets(buf, 120, stdin);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    fun();
    return 0;
}
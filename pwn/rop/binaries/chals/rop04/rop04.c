// gcc -g -O0 -ldl -no-pie -fno-stack-protector -no-pie rop04.c -o rop04
#include <stdio.h>
#include <stdlib.h>

void fun() {
    char buf[100];
    printf("Please don't take my flag.\n");
    printf("Just tell me your name: ");

    fgets(buf, 130, stdin);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    fun();
    return 0;
}
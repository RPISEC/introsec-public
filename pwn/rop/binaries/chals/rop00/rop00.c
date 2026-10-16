// gcc -g -O0 -ldl -no-pie -fno-stack-protector -no-pie rop00.c -o rop00
#include <stdio.h>
#include <stdlib.h>

void win() {
    char flag[64];
    FILE *f = fopen("flag", "r");
    if (f == NULL) {
        printf("Flag file is missing.\n");
        exit(0);
    }
    fgets(flag, 64, f);
    puts(flag);
    exit(0);
}

void fun() {
    char buf[16];
    printf("Please don't take my flag.\n");
    printf("Just tell me your name: ");
    fgets(buf, 48, stdin);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    fun();
    return 0;
}
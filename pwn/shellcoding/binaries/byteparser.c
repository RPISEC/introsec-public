#include <stdio.h>
#include <stdlib.h>

//gcc byteparser.c -o byteparser -fno-stack-protector -no-pie -z execstack

int main(void){

    char code[48];
    printf("Enter the bytes of your shellcode here: ");
    fgets(code, sizeof(code), stdin);

    ((void(*)())code)(); // This will call your shellcode automatically! Don't worry about overwriting the return address
    return 0;
}

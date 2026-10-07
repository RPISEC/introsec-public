#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//gcc nullbyte.c -o nullbyte

int main(void){

    char first[12];
    char second[12];
    memset(first, 0, sizeof(first));
    memset(second, 0, sizeof(second));

    printf("Enter your bytes here:\n");
    fgets(first, sizeof(first), stdin);
    strcpy(second, first);

    printf("Here's what is stored in the first buffer (after the fgets()): ");
    for (int i = 0; i < sizeof(first); i++)
        printf("%02x ", first[i]);
    printf("\n");

    printf("Here's what is stored in the second buffer (after the strcpy()): ");
    for (int i = 0; i < sizeof(second); i++)
        printf("%02x ", second[i]);
    printf("\n");

    return 0;
}

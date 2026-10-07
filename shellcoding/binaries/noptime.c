#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

#define ARRAY_SIZE 1024  // Size of the NOP sled array

// gcc noptime.c -o noptime -fno-stack-protector -no-pie -z execstack -Wno-all

void execute_shellcode(uint8_t *array, size_t offset) {
  if (array[offset] == 0) {
    printf("Nothing detected at offset %zu. Exiting...\n", offset);
    exit(0);
  }

  printf("Executing shellcode at offset %zu...\n", offset);
  ((void (*)())(array + offset))();
}

int main() {
  uint8_t array[ARRAY_SIZE] = {0};  // Initialize array with NOPs (zeros)
  size_t random_offset;

  // Seed random number generator
  srand(time(NULL));

  printf("Welcome to the challenge!\n");

  // Get user input for shellcode
  printf("Enter your input:\n> ");
  char input[ARRAY_SIZE];  // Match size of the array
  fgets(input, sizeof(input), stdin);

  // Remove newline character from input
  size_t input_length = strcspn(input, "\n");
  input[input_length] = '\0';

  // Copy input into the array
  strncpy((char *)array, input, ARRAY_SIZE - 1);
  array[ARRAY_SIZE - 1] = '\0';

  printf("Checking array.\n");

  // Pick a random offset in the array
  random_offset = rand() % ARRAY_SIZE;

  // Execute shellcode at the random offset
  execute_shellcode(array, random_offset);

  return 0;
}

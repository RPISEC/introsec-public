#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/mman.h>

// Function to validate shellcode for disallowed instructions (e.g., "mov")
int validate_shellcode(const char *shellcode, int size) {


//   Opcodes for `mov`
  const char disallowed_opcodes[] = {
    0x89, 0x8B,          // General-purpose `mov` instructions
    0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF // `mov` with immediate values
  };

  // Opcodes for `push or pop`
//   const char disallowed_opcodes[] = {
//     // PUSH opcodes
//     0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, // `push` rax to rdi
//     0x68,                                          // `push imm32`
//     0x6A,                                          // `push imm8`

//     // POP opcodes
//     0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F  // `pop` rax to rdi
//   };

//   const char disallowed_opcodes[] = {
//     'b', 'i', 'n', 's', 'h', '/'
//   };


  int disallowed_count = sizeof(disallowed_opcodes) / sizeof(disallowed_opcodes[0]);

  // look for for disallowed opcodes
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < disallowed_count; j++) {
      if (shellcode[i] == disallowed_opcodes[j]) {
        printf("Invalid shellcode: instruction detected at byte %u (0x%02X)\n", i, shellcode[i]);
        return 0; // Invalid shellcode
      }
    }
  }

  return 1; // Valid shellcode
}

void vuln() {
  char buffer[128];

  printf("Give your input:\n> ");
  fgets(buffer, sizeof(buffer), stdin);

  // Validate the shellcode
  if (!validate_shellcode(buffer, sizeof(buffer))) {
    printf("Shellcode validation failed. Execution aborted.\n");
    return;
  }

  printf("Shellcode is valid. Executing...\n");
  ((void (*)())buffer)();
}

int main() {
  setvbuf(stdout, NULL, _IONBF, 0);
  printf("Welcome to the challenge!\n");
  vuln();
  return 0;
}

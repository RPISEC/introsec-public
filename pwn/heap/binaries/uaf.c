#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef void (*action_fn)(void);

struct Item {
    char name[24];
    action_fn action;
};

struct Item *item = NULL;

void lose(void) {
    puts("Nothing interesting happens.");
}

void win(void) {
    puts("\nYou win!!");
}

void create_item(void) {
    if (item != NULL) {
        puts("An item already exists.");
        return;
    }

    item = malloc(sizeof(struct Item));
    if (!item) {
        perror("malloc");
        exit(1);
    }

    snprintf(item->name, sizeof(item->name), "ordinary item");
    item->action = lose;

    puts("Item created.");
}

void delete_item(void) {
    if (!item) {
        puts("No item exists.");
        return;
    }

    free(item);
    puts("Item deleted.");
}

void edit_action(void) {
    if (!item) {
        puts("No item pointer available.");
        return;
    }

    printf("New action address (hex): ");

    uintptr_t address;
    if (scanf("%" SCNxPTR, &address) != 1) {
        puts("Invalid address.");
        exit(1);
    }

    item->action = (action_fn)address;
    puts("Action updated.");
}

void use_item(void) {
    if (!item) {
        puts("No item pointer available.");
        return;
    }

    item->action();
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    int choice;

    puts("Use it After you Free it!");

    while (1) {
        puts("\n1. Create item");
        puts("2. Delete item");
        puts("3. Change action address");
        puts("4. Use item");
        puts("5. Exit");
        printf("> ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1: create_item(); break;
            case 2: delete_item(); break;
            case 3: edit_action(); break;
            case 4: use_item(); break;
            case 5: return 0;
            default: puts("Invalid choice.");
        }
    }

    return 0;
}


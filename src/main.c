// main.c
#include <stdio.h>
#include <stdlib.h>
#include "user_manager.h"
#include "data_processor.h"

int main() {
    // Memory Leak 1: Allocating memory without freeing
    char *leaked_string = malloc(300);
    sprintf(leaked_string, "This memory will never be freed");

    // Memory Leak 2: Creating users without proper cleanup
    User *user1 = create_user("Alice", 30);
    User *user2 = create_user("Bob", 25);

    // Memory Leak 3: Processing data without freeing
    int *data = generate_large_data(2000);
    process_data(data, 2000);

    // Intentionally not freeing resources
    return 0;
}

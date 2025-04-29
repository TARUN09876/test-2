// user_manager.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/user_manager.h"

User* create_user(const char *name, int age) {
    // Memory Leak: Allocating memory for user but never freeing
    User *new_user = malloc(sizeof(User));
    
    // Memory Leak: Allocating memory for name but not tracked for free
    new_user->name = malloc(strlen(name) + 1);
    strcpy(new_user->name, name);
    
    new_user->age = age;
    return new_user;
}

void print_user(User *user) {
    // Memory Leak: No mechanism to free the user or name
    printf("Name: %s, Age: %d\n", user->name, user->age);
}

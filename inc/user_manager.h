// user_manager.h
#ifndef USER_MANAGER_H
#define USER_MANAGER_H

typedef struct {
    char *name;
    int age;
} User;

User* create_user(const char *name, int age);
void print_user(User *user);

#endif

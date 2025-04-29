// tests_main.cpp
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include <cstring>

extern "C" {
    #include "user_manager.h"
    #include "data_processor.h"
}
// User Manager Tests
TEST_GROUP(UserManagerTestGroup) {
    void setup() {}
    void teardown() {}
};

// Test user creation with various scenarios
TEST(UserManagerTestGroup, CreateUserTest_FullName) {
    User* user = create_user("John Doe", 30);
    
    CHECK(user != NULL);
    STRCMP_EQUAL("John Doe", user->name);
    CHECK_EQUAL(30, user->age);
    
    free(user->name);
    free(user);
}

TEST(UserManagerTestGroup, CreateUserTest_SingleCharName) {
    User* user = create_user("A", 25);
    
    CHECK(user != NULL);
    STRCMP_EQUAL("A", user->name);
    CHECK_EQUAL(25, user->age);
    
    free(user->name);
    free(user);
}

TEST(UserManagerTestGroup, CreateUserTest_EmptyName) {
    User* user = create_user("", 40);
    
    CHECK(user != NULL);
    STRCMP_EQUAL("", user->name);
    CHECK_EQUAL(40, user->age);
    
    free(user->name);
    free(user);
}

TEST(UserManagerTestGroup, CreateUserTest_ZeroAge) {
    User* user = create_user("Zero", 0);
    
    CHECK(user != NULL);
    STRCMP_EQUAL("Zero", user->name);
    CHECK_EQUAL(0, user->age);
    
    free(user->name);
    free(user);
}

TEST(UserManagerTestGroup, UserNameAllocationTest_SpecialCharacters) {
    User* user = create_user("John@Doe", 35);
    
    CHECK(user->name != NULL);
    STRCMP_EQUAL("John@Doe", user->name);
    CHECK_EQUAL(8, strlen(user->name));
    
    free(user->name);
    free(user);
}

// Data Processor Tests
TEST_GROUP(DataProcessorTestGroup) {
    void setup() {}
    void teardown() {}
};

TEST(DataProcessorTestGroup, GenerateLargeDataTest) {
    int size = 100;
    int* data = generate_large_data(size);
    
    CHECK(data != NULL);
    
    for (int i = 0; i < size; i++) {
        CHECK_COMPARE(data[i], >=, 0);
        CHECK_COMPARE(data[i], <, 1000);
    }
    
    free(data);
}

TEST(DataProcessorTestGroup, ProcessDataTest) {
    int size = 20;
    int* data = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        data[i] = i + 1;
    }
    
    process_data(data, size);
    
    free(data);
}

#ifdef PRINT_USER_AVAILABLE
TEST(UserManagerTestGroup, PrintUserTest) {
    // Redirect stdout to capture output
    // This is a placeholder and might need platform-specific implementation
    User* user = create_user("Test User", 50);
    
    print_user(user);
    
    // Add assertions to verify output if needed
    
    free(user->name);
    free(user);
}
#endif






int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}

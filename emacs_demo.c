#include <stdio.h>
#include <string.h>
#define MAX_USERS 5

typedef struct {
    int id;
    char name[32];
    int score;
} User;

void print_line(void) {
    printf("----------------------------------------\n");
}

void print_user(User user) {
    printf("ID: %d\n", user.id);
    printf("Name: %s\n", user.name);
    printf("Score: %d\n", user.score);
}

int total_score(User users[], int count) {
    int total = 0;

    for (int i = 0; i < count; i++) {
        total += users[i].score;
    }

    return total;
}

double average_score(User users[], int count) {
    if (count == 0) {
        return 0.0;
    }

    return (double)total_score(users, count) / count;
}

User find_test_user(User users[], int count) {
    User best_user = users[0];

    for (int i = 1; i < count; i++) {
        if (users[i].score > best_user.score) {
            best_user = users[i];
        }
    }
    return best_user;
}

void print_report(User users[], int count) {
    print_line();
    printf("User Report\n");
    print_line();

    for (int i = 0; i < count; i++) {
        print_user(users[i]);
        print_line();
    }

    printf("Total Score: %d\n", total_score(users, count));
    printf("Average Score: %.2f\n", average_score(users, count));

    User test_user = find_test_user(users, count);
    printf("Top User: %s\n", test_user.name);
}

int main(void) {
    User users[MAX_USERS] = {
        {1, "yuzu", 95},
        {2, "sakura", 82},
        {3, "taro", 76},
        {4, "mikan", 88},
        {5, "neko", 100},
    };

    int user_count = MAX_USERS;

    printf("Starting user score program...\n");

    print_report(users, user_count);

    printf("Program finished successfully.\n");

    return 0;
}
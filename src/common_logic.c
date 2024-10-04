#include "common_logic.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void play_round(char *question, char *correct_answer, char *user_name) {
    char user_answer[50];
    usleep(200000);
    printf("| Question: %s\n", question);
    usleep(200000);
    printf("| Your answer: ");
    scanf("%49s", user_answer);

    if (strcmp(user_answer, correct_answer) == 0) {
        usleep(200000);
        printf("| Correct!\n");
    } else {
        usleep(200000);
        printf("| '%s' is wrong answer ;(. Correct answer was '%s'.\n", user_answer, correct_answer);
        usleep(200000);
        printf("|  Wanna try again, %s?\n", user_name);
        printf("| \n");
    }
}
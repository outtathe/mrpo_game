#include <stdio.h>
#include <stdbool.h>
#include "common_logic.h"

void play_round(char *question, char *correct_answer, char *user_name) {
    char user_answer[50];
    printf("Question: %s\n", question);
    printf("Your answer: ");
    scanf("%49s", user_answer);

    if (strcmp(user_answer, correct_answer) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("'%s' is wrong answer ;(. Correct answer was '%s'.\n", user_answer, correct_answer);
        printf("Let's try again, %s!\n\n", user_name);
    }
}
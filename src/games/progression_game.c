#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common_logic.h"
#include "../utils/utils.h"

void progression_game(char *user_name) {
    printf("What number is missing in the progression?\n");
    for (int i = 0; i < 3; i++) {
        int length = get_random_number(5, 10);
        int ratio = get_random_number(2, 5);
        int start = get_random_number(1, 10);
        int missing_index = get_random_number(0, length - 1);

        char question[100] = "";
        char correct_answer[50];
        int current = start;
        for (int j = 0; j < length; j++) {
            if (j == missing_index) {
                strcat(question, ".. ");
                sprintf(correct_answer, "%d", current);
            } else {
                char buffer[10];
                sprintf(buffer, "%d ", current);
                strcat(question, buffer);
            }
            current *= ratio;
        }

        play_round(question, correct_answer, user_name);
    }
    printf("Congratulations, %s!\n", user_name);
}
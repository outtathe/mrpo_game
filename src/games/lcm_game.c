#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../common_logic.h"
#include "../utils/utils.h"

void lcm_game(char *user_name) {
    usleep(150000);
    printf("+----------------------------------------------------+\n");
    usleep(150000);
    printf("|         Great! You choose the lcm-game!            |\n");
    usleep(150000);
    printf("| Find the smallest common multiple of given numbers.|\n");
    usleep(150000);
    for (int i = 0; i < 3; i++) {
        int num1 = get_random_number(1, 50);
        int num2 = get_random_number(1, 50);
        int num3 = get_random_number(1, 50);
        char question[100];
        sprintf(question, "|%d|-|%d|-|%d|", num1, num2, num3);
        int lcm = calculate_lcm(calculate_lcm(num1, num2), num3);
        char correct_answer[50];
        sprintf(correct_answer, "%d", lcm);

        play_round(question, correct_answer, user_name);
    }
    usleep(150000);
    printf("Congratulations, %s!\n", user_name);
}
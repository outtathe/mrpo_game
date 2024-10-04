#include <stdio.h>
#include "common_logic.h"
#include "./games/games.h"

int main() {
    printf("Welcome to the Brain Games!\n");
    char user_name[50];
    printf("May I have your name? ");
    scanf("%49s", user_name);
    printf("Hello, %s!\n\n", user_name);

    int game_choice;
    printf("Hello, %s, you can play one of these games:\n", user_name);
    printf("1. Game LCM\n");
    printf("2. Game Progression\n");
    printf("Please enter the number of the game you want to play: ");
    scanf("%d", &game_choice);

    switch (game_choice) {
        case 1:
            gcd_game(user_name);
            break;
        case 2:
            progression_game(user_name);
            break;
        default:
            printf("Invalid choice. Please restart the game and select a valid option.\n");
            break;
    }

    return 0;
}
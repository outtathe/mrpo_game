#include <stdio.h>

#include "./games/games.h"
#include "common_logic.h"

int main() {
    printf("+----------------------------------+\n");
    printf("|    Welcome to the Brain Games!   |\n");
    printf("+----------------------------------+\n");
    char user_name[50];
    printf("|    May I have your name?         |\n");
    printf("     Enter your name: ");
    scanf("%49s", user_name);
    printf("+----------------------------------+\n");
    // printf("Hello, %s!\n\n", user_name);

    int game_choice;
    printf("  Hello, %s!\n", user_name);
    printf("| You can play one of these games: |\n");
    printf("| 1. Game LCM                      |\n");
    printf("| 2. Game Progression              |\n");
    printf("Please enter the number of the game you want to play: ");
    scanf("%d", &game_choice);

    switch (game_choice) {
        case 1:
            //   lcm_game(user_name);
            printf("Okay, you choosed lcm game!\n");
            break;
        case 2:
            //   progression_game(user_name);
            printf("Okay, you choosed progression game!\n");
            break;
        default:
            printf(
                "Invalid choice. Please restart the game and select a valid "
                "option.\n");
            break;
    }

    return 0;
}
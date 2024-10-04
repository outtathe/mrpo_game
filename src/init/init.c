#include <stdio.h>
#include <unistd.h>
#include "../games/games.h"
#include "../common_logic.h"

int init() {
    printf("+----------------------------------+\n");
    usleep(200000);
    printf("|    Welcome to the Brain Games!   |\n");
    usleep(200000);
    printf("+----------------------------------+\n");
    usleep(200000);
    char user_name[50];
    printf("|    May I have your name?\n");
    usleep(200000);
    printf("|    Enter your name: ");
    scanf("%49s", user_name);
    printf("+----------------------------------+\n");
    usleep(400000);
    int game_choice;
    printf("| Hello, %s!\n", user_name);
    while (1) {
        usleep(200000);
        printf("+----------------------------------+\n");
        usleep(200000);
        printf("| You can play one of these games: |\n");
        usleep(200000);
        printf("| 1. Game LCM                      |\n");
        usleep(200000);
        printf("| 2. Game Progression              |\n");
        usleep(200000);
        printf("| 3. Exit                          |\n");
        usleep(200000);
        printf("| Please enter the number of the game\n| that you want to play (or 3 to quit): ");
        scanf("%d", &game_choice);
        if (game_choice == 3) {
            printf("| Goodbye, %s!\n", user_name);
            break;
        }

        switch (game_choice) {
            case 1:
                lcm_game(user_name);
                break;
            case 2:
                progression_game(user_name);
                break;
            default:
                printf(
                    "Invalid choice. Please restart the game and select a valid "
                    "option.\n");
                break;
        }
    }

    return 0;
}
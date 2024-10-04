Project Structure Overview for "Brain Games":

To make the project easy to navigate and maintain, we'll use a modular approach, placing the common logic in reusable modules and separating individual games into dedicated files. Below, I'll describe the suggested directory and file structure, along with their purposes, as well as some sample code snippets for each file. The key idea here is to maintain DRY (Don't Repeat Yourself) principles by extracting common game logic.

# Directory Structure

```
BrainGamesProject/
├── Makefile                 # Makefile to compile the project
├── main.c                   # Main entry point of the project
├── common_logic.c           # Contains shared logic used by all games
├── common_logic.h           # Header file for common_logic.c
├── games/                   # Directory containing individual game files
│   ├── gcd_game.c           # Game for "Least Common Multiple (LCM)"
│   ├── progression_game.c   # Game for "Geometric Progression"
│   └── games.h              # Header for all games, exposing their interfaces
└── utils/
    ├── utils.c              # Contains various helper functions (e.g., random number generation)
    └── utils.h              # Header file for utils.c
```

## 1. `main.c` - Main Entry Point

This is the main file that initializes the games and manages user interaction:

```c
#include <stdio.h>
#include "common_logic.h"
#include "games.h"

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
```

## 2. `common_logic.c` - Common Logic Shared by All Games

Contains the common game flow logic:

```c
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
```

## 3. `common_logic.h` - Header for Common Logic

```c
#ifndef COMMON_LOGIC_H
#define COMMON_LOGIC_H

void play_round(char *question, char *correct_answer, char *user_name);

#endif
```

## 4. `games/gcd_game.c` - Game for "Least Common Multiple (LCM)"

Contains the implementation for the "LCM Game":

```c
#include <stdio.h>
#include <stdlib.h>
#include "common_logic.h"
#include "utils.h"

void gcd_game(char *user_name) {
    printf("Find the smallest common multiple of given numbers.\n");
    for (int i = 0; i < 3; i++) {
        int num1 = get_random_number(1, 50);
        int num2 = get_random_number(1, 50);
        int num3 = get_random_number(1, 50);
        char question[100];
        sprintf(question, "%d %d %d", num1, num2, num3);

        int lcm = calculate_lcm(calculate_lcm(num1, num2), num3);
        char correct_answer[50];
        sprintf(correct_answer, "%d", lcm);

        play_round(question, correct_answer, user_name);
    }
    printf("Congratulations, %s!\n", user_name);
}
```

## 5. `games/progression_game.c` - Game for "Geometric Progression"

Contains the implementation for the "Geometric Progression Game":

```c
#include <stdio.h>
#include <stdlib.h>
#include "common_logic.h"
#include "utils.h"

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
```

## 6. `games/games.h` - Header File for All Games

```c
#ifndef GAMES_H
#define GAMES_H

void gcd_game(char *user_name);
void progression_game(char *user_name);

#endif
```

## 7. `utils/utils.c` - Helper Functions

Contains utility functions like random number generation and calculating the LCM:

```c
#include <stdlib.h>
#include "utils.h"

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int calculate_lcm(int a, int b) {
    int gcd = calculate_gcd(a, b);
    return (a * b) / gcd;
}

int calculate_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

## 8. `utils/utils.h` - Header File for Utils

```c
#ifndef UTILS_H
#define UTILS_H

int get_random_number(int min, int max);
int calculate_lcm(int a, int b);
int calculate_gcd(int a, int b);

#endif
```

# Compilation and Running

To compile the project, you can use the `Makefile` to manage the build process:

```make
CC = gcc
CFLAGS = -Wall

all: main

main: main.c common_logic.c games/gcd_game.c games/progression_game.c utils/utils.c
	$(CC) $(CFLAGS) -o brain_games main.c common_logic.c games/gcd_game.c games/progression_game.c utils/utils.c

clean:
	rm -f brain_games

check-style:
	clang-format -n ./src/*.c

format:
	clang-format -i ./src/*.c
```

This will ensure that all the components are compiled together, and any dependencies are appropriately managed.
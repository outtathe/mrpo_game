CC = gcc
CFLAGS = -Wall -Wextra -Werror 

all: main

main: main.c common_logic.c games/gcd_game.c games/progression_game.c utils/utils.c
	$(CC) $(CFLAGS) -o brain_games main.c common_logic.c games/gcd_game.c games/progression_game.c utils/utils.c

check-style:
	clang-format -n *.c *.h ./games/*.c ./games/*.h ./utils/*.c ./utils/*.h

format:
	clang-format -i *.c *.h ./games/*.c ./games/*.h ./utils/*.c ./utils/*.h

clean:
	rm -f brain_games
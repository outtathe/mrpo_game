CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c common_logic.c games/lcm_game.c games/progression_game.c utils/utils.c ./init/init.c
OBJ = $(SRC:.c=.o)
CLANG_FORMAT_CONFIG = ../materials/linters/.clang-format

all: brain_games

brain_games: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

style_check: copy-clang-format
	clang-format -n *.c *.h ./games/*.c ./games/*.h ./utils/*.c ./utils/*.h ./init/*.c ./init/*.h
	$(MAKE) remove-clang-format

format: copy-clang-format
	clang-format -i *.c *.h ./games/*.c ./games/*.h ./utils/*.c ./utils/*.h ./init/*.c ./init/*.h
	$(MAKE) remove-clang-format

copy-clang-format:
	cp $(CLANG_FORMAT_CONFIG) ./

remove-clang-format:
	rm -f ./.clang-format

cppcheck:
	cppcheck --enable=all --suppress=checkersReport --inconclusive --std=c99 --suppress=missingIncludeSystem $(SRC)

clean:
	rm -f brain_games $(OBJ)
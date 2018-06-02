C = gcc
flag = -c -Wall -Werror -std=c99

all: ./bin/games

./build/game_menu.o: ./src/game_menu.c
	gcc $(flag) ./src/game_menu.c -o ./build/game_menu.o

./build/tick-tack-toe.o: ./src/tick-tack-toe.c
	gcc $(flag) ./src/tick-tack-toe.c -o ./build/tick-tack-toe.o

./build/nim.o: ./src/nim.c
	gcc $(flag) ./src/nim.c -o ./build/nim.o

./bin/games: ./build/game_menu.o ./build/nim.o ./build/tick-tack-toe.o
	gcc ./build/game_menu.o ./build/tick-tack-toe.o ./build/nim.o -o ./bin/games

.PHONY: clean
clean:
	rm -rf ./build/*.o

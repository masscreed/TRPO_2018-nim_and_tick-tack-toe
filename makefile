C = gcc
flag = -c -Wall -Werror -std=c99

build:
	mkdir build
bin:
	mkdir bin

all: ./bin/game_menu

./bin/game_menu: ./build/game_menu.o ./build/nim.o ./build/tick-tack-toe.o
	gcc ./build/game_menu.o ./build/nim.o ./build/tick-tack-toe.o -o ./bin/game_menu

./build/game_menu.o: ./src/game_menu.c
	gcc $(flag) ./src/game_menu.c -o ./build/game_menu.o

./build/src/nim.o: ./src/nim.c
	gcc $(flag) ./src/nim.c -o ./build/nim.o

./build/src/tick-tack-toe.o: ./src/tick-tack-toe.c
	gcc $(flag) ./src/tick-tack-toe.c -o ./build/tick-tack-toe.o

.PHONY: clean
clean:
	rm -rf ./build/*.o
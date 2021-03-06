#include <stdio.h>
#include <stdlib.h>
#include "tick-tack-toe.h"
#include "nim.h"

int main()
{
	system("clear");
	int end_prog = 0;
	char num;
	
	while (end_prog == 0) {
		printf("Game menu:\n");
		printf("1. Game nim\n");
		printf("2. Game tick-tack-toe\n");
		printf("3. Top in game nim\n");
		printf("4. Top in game tick-tack-toe\n");
		printf("5. Exit\n");
		num = mygetch();
		
		while (!(num >= '1' && num <= '5')) {
			printf("\nEnter correct data");
			num = mygetch();
			printf("\n");
		}
	
		printf("\n");
		
		switch (num - '0') {
		
		case 1: {
			system("clear");
			start_game_nim();
			break;
		};
		
		case 2: {
			system("clear");
			start_game_tick();
			break;			
		};
		
		case 3: {
			print_top_nim();
			break;
		};
		
		case 4: {
			print_top_tick();
			break;
		};
		
		case 5: {
			end_prog = 1;
			break;			
		};
		}
	}

	return 0;
}

void print_top_tick()
{
	system("clear");
	FILE *read_score;
	char name[length_name];
	int win, loss, i = 0;
	
	if ((read_score = fopen("score_tick.txt", "rt")) != NULL) {
		
		while (!feof(read_score)) {
			fscanf(read_score, "%s%d%d", name, &win, &loss);
			i++;
		}
		
		fclose(read_score);
	}
	
	if ((read_score = fopen("score_tick.txt", "rt")) != NULL) {
		
		while (!feof(read_score) && i - 1 > 0) {
			fscanf(read_score, "%s%d%d", name, &win, &loss);
			printf("%s win:%d loss:%d\n", name, win, loss);
			i--;
		}
	
		fclose(read_score);
	}

	printf("\n");
}

void print_top_nim()
{
	system("clear");
	FILE *read_score;
	char name[length_name];
	int win, loss, i = 0;
	
	if ((read_score = fopen("score_nim.txt", "rt")) != NULL) {
		while (!feof(read_score)) {
			fscanf(read_score, "%s%d%d", name, &win, &loss);
			i++;
		}
		
		fclose(read_score);
	}
	
	if ((read_score = fopen("score_nim.txt", "rt")) != NULL) {
		while (!feof(read_score) && i - 1 > 0) {
			fscanf(read_score, "%s%d%d", name, &win, &loss);
			printf("%s win:%d loss:%d\n", name, win, loss);
			i--;
		}
	
		fclose(read_score);
	}

	printf("\n");
}
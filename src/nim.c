#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "tick-tack-toe.h"
#include "nim.h"

int end_check, end_quit;

void mass_input(int mass[3]) { //считывает количество спичек в каждой кучке
	char str[256];
	int n = 0;
	
	while (n == 0) {
		printf("\nEnter the number of matches in the first pile\n");
		gets(str);
		if ( isdigit(str[0]) ) {
			mass[0] = atoi (str);
			n++;
		} else {
			printf("ERROR");
		}
		if (mass[0] <= 0) {
			n--;
		}
	}
	n--;
	while (n == 0) {
		printf("\nEnter the number of matches in the second pile\n");
		gets(str);
		if ( isdigit(str[0]) ) {
			mass[1] = atoi (str);
			n++;
		} else {
			printf("ERROR");
		}
	}
	n--;
	while (n == 0) {
		printf("\nEnter the number of matches in the third pile\n");
		gets(str);
		if ( isdigit(str[0]) ) {
			mass[2] = atoi (str);
			n++;
		} else {
			printf("ERROR");
		}
	}
	n--;
	return ;
}

void mass_output(int mass[3]) { //выводит массив из количества спичек в каждой кучке
	system ("clear");
	printf("\n");

	for(int i=1; i<4; i++) {
		printf("%d\t", i);
	}

	printf("\n");

	for(int i=0; i<3; i++) {
		printf("%d\t", mass[i]);
	}

	printf("\n");
	
	return ;
}

int heap_selection() { //считывает выбранную кучку
	int input;
	char str[256];
	int n = 0;
	
	while (n == 0 && end_check == 0) {
		printf("\nSelect a pile\n");
		gets(str);
		if (!(str[0] == 'q' && end_nim_quit() == 1)) {
			if ( isdigit(str[0]) ) {
				input = atoi (str);
				n++;
			} else {
				printf("ERROR");
			}
		}
	}
	
	return input;
}

int heap_check(int input, int mass[3], int f) { //проверяет корректно ли введена кучка
	if ( input >= 1 && input <= 3 ) {
		if ( mass[input-1] > 0 ) {
			f--;
		} else {
			printf("\nERROR\n");
		}
	} else { 
		printf("\nERROR\n");
	}
	
	return f;
}

int take_number_matches() { //считывает сколько спичек взять из кучки
	int num, k = 0;
	char str[256];
	
	while (k == 0 && end_check == 0) {
		printf("\nHow many matches to take?\n");
		gets(str);
		if (!(str[0] == 'q' && end_nim_quit() == 1)) {
			if ( isdigit(str[0]) ) {
				num = atoi (str);
				k++;
			} else {
				printf("ERROR");
			}
		}
	}
	
	return num;
}

void heap_change(int* mass, int i, int num) { //подсчет кучки после take_number_matches
	mass[i] = mass[i] - num;
}

int mechanics_of_the_game (int mass[3]) { //механика игры
	int num, input; //num - количество взятых спичек, input - выбранная кучка
	int k = 1, f, i; //k - проверка на очередь игрока, f - проверка на правельность введеного значения
	
	while ( (mass[0] > 0 || mass[1] > 0 || mass[2] > 0) && end_check == 0) {
		if ( k == 1) {
			printf("\nPlayer # 1 is walking\n");
			f = 1;
			
			while ( f == 1 && end_check == 0) {
				input = heap_selection();
				if (end_check == 0)
					f = heap_check(input, mass, f);
			}
			
			if (end_check == 0) {
				switch ( input ) {
					case 1: {
						f = 1;
						while ( f == 1 && end_check == 0) {
							
							num = take_number_matches();
							if (end_check == 0) {
								if (num <= mass[0]) {
									i = 0;
									heap_change(mass, i, num);
									mass_output(mass);
									f--;
								} else {
									printf("\nERROR\n");
								}
							}
						}
						break;
					}
					case 2: {
						f = 1;
						while ( f == 1 && end_check == 0) {
							
							num = take_number_matches();
							if (end_check == 0) {
								if (num <= mass[1]) {
									i = 1;
									heap_change(mass, i, num);
									mass_output(mass);
									f--;
								} else {
									printf("\nERROR\n");
								}
							}
						}
						break;
					}
					case 3: {
						f = 1;
						while ( f == 1 && end_check == 0) {
							
							num = take_number_matches();
							if (end_check == 0) {
								if (num <= mass[2]) {
									i = 2;
									heap_change(mass, i, num);
									mass_output(mass);
									f--;
								} else {
									printf("\nERROR\n");
								}
							}
						}
						break;
					}
				}
				k++;
			}
		} else {
			printf("\nPlayer # 2 is walking\n");
			f = 1;
			while ( f == 1 && end_check == 0) {
				input = heap_selection();
				if (end_check == 0)
					f = heap_check(input, mass, f);
			}
			if (end_check == 0) { 
				switch ( input ) {
					case 1: {
						f = 1;
						while ( f == 1 && end_check == 0) {
							
							num = take_number_matches();
							if (end_check == 0) {
								if (num <= mass[0]) {
									i = 0;
									heap_change(mass, i, num);
									mass_output(mass);
									f--;
								} else {
									printf("\nERROR\n");
								}
							}
						}
						break;
					}
					case 2: {
						f = 1;
						while ( f == 1 && end_check == 0) {
							
							num = take_number_matches();
							if (end_check == 0) {
								if (num <= mass[1]) {
									i = 1;
									heap_change(mass, i, num);
									mass_output(mass);
									f--;
								} else {
									printf("\nERROR\n");
								}
							}
						}
						break;
					}
					case 3: {
						f = 1;
						while ( f == 1 && end_check == 0) {
							
							num = take_number_matches();
							if (end_check == 0) {
								if (num <= mass[2]) {
									i = 2;
									heap_change(mass, i, num);
									mass_output(mass);
									f--;
								} else {
									printf("\nERROR\n");
								}
							}
						}
						break;
					}
				}
				k--;
			}
		}
	}
	return k;
}

int end_nim(name *names_players, score *score, int status)
{
	if(end_quit == 1)
	{
		return 1;
	}
	else if( status == 0)
	{
		printf("Enter n if you do not want to continue playing, else press any key\n");
		char end;
		end = getche();
		if( end == 'n') {
			system("clear");
			return 1;
		} else {
			printf("\nRestart game\n\n");
		}
	}
	return 0;
}

int end_nim_quit()
{
	char end;
	printf("\nAre you sure you want to finish the game?\n");
	printf("If you sure press y, else press any key\n");
	end = getche();
	if( end == 'y')
	{
		system("clear");
		end_check = 1;
		end_quit = 1;
		return 1;
	}
	return 0;
}

void start_game_nim() {
	name *names_players = malloc(sizeof(name));
	score *set_score = malloc(sizeof(score));
	enter_names(names_players, set_score);
	int player_win;
	end_check = 0;
	end_quit = 0;
	
	do {
		int mass[3];
		end_check = 0;
		
		mass_input(mass);
		
		mass_output(mass);
		
		player_win = mechanics_of_the_game(mass);
		if (end_check != 1){
			if (player_win % 2 == 0) {
				set_score->win_players1++;
				set_score->loss_players2++;
				printf("Name: %s\t", names_players->name_players1);
				printf("Count win: %d, loss: %d\n\n", set_score->win_players1, set_score->loss_players1);
			} else {
				set_score->win_players2++;
				set_score->loss_players1++;
				printf("Name: %s\t", names_players->name_players2);
				printf("Count win: %d, loss: %d\n\n", set_score->win_players2, set_score->loss_players2);
			}
			end_check = 1;
		}
	} while (end_nim(names_players, set_score, 0) == 0);
}
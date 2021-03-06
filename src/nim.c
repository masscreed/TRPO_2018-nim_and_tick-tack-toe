#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tick-tack-toe.h"
#include "nim.h"

int end_check, end_quit;

void get_string(char str[])
{
	char c;
	int i, k = 0;
	
	for (i = 0; (i < 256 - 1) && k == 0; i++) {
		c = getchar();
		if (c != '-') {
			if (i == 0 && c != '0') {
				str[i] = c;
				str[i + 1] = '\0';
				if(str[i] == '\n')
					k = 1;
			} else if (i > 0) {
				str[i] = c;
				str[i + 1] = '\0';
				if(str[i] == '\n')
					k = 1;
			} else {
				i--;
			}
		} else {
			i--;
		}
	}
	
	if (i >= 256 - 1)
		while(getchar() != '\n');
}

void mass_input(int mass[3]) //считывает количество спичек в каждой кучке
{
	char str[256];
	int n = 0;

	while (n == 0) {
		printf("\nEnter the number of matches in the first pile\n");
		get_string(str);
		if (isdigit(str[0])) {
			mass[0] = atoi(str);
			n++;
		} else {
			printf("ERROR");
		}
	}
	
	n--;
	
	while (n == 0) {
		printf("\nEnter the number of matches in the second pile\n");
		get_string(str);
		if (isdigit(str[0])) {
			mass[1] = atoi(str);
			n++;
		} else {
			printf("ERROR");
		}
	}
	
	n--;
	
	while (n == 0) {
		printf("\nEnter the number of matches in the third pile\n");
		get_string(str);
		if (isdigit(str[0])) {
			mass[2] = atoi(str);
			n++;
		} else {
			printf("ERROR");
		}
	}
	
	n--;
	
	return ;
}

void mass_output(int mass[3]) //выводит массив из количества спичек в каждой кучке
{
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

int heap_selection() //считывает выбранную кучку
{
	int input;
	char str[256];
	int n = 0;

	while (n == 0 && end_check == 0) {
		printf("\nSelect a pile\n");
		get_string(str);
		
		if (!(str[0] == 'q' && end_nim_quit() == 1)) {
			if (isdigit(str[0])) {
				input = atoi(str);
				n++;
			} else {
				printf("ERROR");
			}
		}
	}

	return input;
}

int heap_check(int input, int mass[3]) //проверяет корректно ли введена кучка
{
	if (input >= 1 && input <= 3) {
		if (mass[input-1] > 0) {
			return 0;
		} else {
			printf("\nERROR\n");
			return 1;
		}
	} else { 
		printf("\nERROR\n");
		return 1;
	}

	return 0;
}

int take_number_matches() //считывает сколько спичек взять из кучки
{
	int num, k = 0;
	char str[256];

	while (k == 0 && end_check == 0) {
		printf("\nHow many matches to take?\n");
		get_string(str);
		if (!(str[0] == 'q' && end_nim_quit() == 1)) {
			if (isdigit(str[0])) {
				num = atoi(str);
				if( num != 0)
					k++;
				else
					printf("ERROR");
			} else {
				printf("ERROR");
			}
		}
	}

	return num;
}

void heap_change(int *mass, int i, int num) //подсчет кучки после take_number_matches
{
	mass[i] = mass[i] - num;
}

int check_correct_matches(int* mass, int i, int num)
{
	if (num > 0) {
		if (num <= mass[i]) {
			heap_change(mass, i, num);
			mass_output(mass);
			return 1;
		}
	}

	return 0;
}

int count_string_nim()
{
	FILE *read_score;
	char name[length_name];
	int win, loss, i = 0;
	
	if ((read_score = fopen("score_nim.txt", "rt")) != NULL) {
		while (!feof(read_score)) {
			fscanf(read_score, "%s%d%d", name, &win, &loss);
			i++;
		}
	
		fclose(read_score);
		return i - 1;
	}
	
	return i;
}

void safe_score_nim(name *names_players, score *score)
{
	char buff[max_safe_score][length_name];
	int win[max_safe_score], loss[max_safe_score], i, t;
	int find_players[] = {0, 0};
	char buff1[length_name], buff2[length_name];
	FILE *safe_score;
	t = count_string_nim();
	i = 0;
	
	if ((safe_score = fopen("score_nim.txt", "rt")) != NULL) {
		while (!feof(safe_score) && t > i) {
			fscanf(safe_score, "%s%d%d", buff[i], &win[i], &loss[i]);
			i++;
		}
		
		fclose(safe_score);
	}
	
	copy_struct_to_string(buff1, buff2, names_players);
	i = t;
	
	for (t = 0; t < i; t++) {
		if (equal_string(buff[t], buff1) == 1) {
			win[t] += score -> win_players1;
			loss[t] += score -> loss_players1;
			find_players[0]++;
		}
		
		if (equal_string(buff[t], buff2) == 1) {
			win[t] += score -> win_players2;
			loss[t] += score -> loss_players2;
			find_players[1]++;
		}
	}

	if (find_players[0] == 0) {
		copy_string( buff[i], buff1);
		win[i] = score -> win_players1;
		loss[i] = score -> loss_players1;
		i++;
	}

	if (find_players[1] == 0) {
		copy_string( buff[i], buff2);
		win[i] = score -> win_players2;
		loss[i] = score -> loss_players2;
		i++;
	}
	
	sort_top(buff, win, loss, i);
	
	if ((safe_score = fopen("score_nim.txt", "wt")) != NULL) {
		for (t = 0; t < i; t++ ) {
			fprintf(safe_score, "%s %d %d\n", buff[t], win[t], loss[t]);	
		}
	
		fclose(safe_score);
	}
}

int mechanics_of_the_game (int mass[3]) //механика игры
{
	int num, input; //num - количество взятых спичек, input - выбранная кучка
	int k = 1, f, i; //k - проверка на очередь игрока, f - проверка на правельность введеного значения

	while ((mass[0] > 0 || mass[1] > 0 || mass[2] > 0) && end_check == 0) {
		if ( k == 1) {
			printf("\nPlayer # 1 is walking\n");
			f = 1;

			while (f == 1 && end_check == 0) {
				input = heap_selection();
				if (end_check == 0)
					f = heap_check(input, mass);
			}

			if (end_check == 0) {
				
				switch (input) {
				
				case 1: {
					f = 1;
					
					while (f == 1 && end_check == 0) {
						num = take_number_matches();
						if (end_check == 0) {
							i = 0;
							if (check_correct_matches(mass, i, num))
								f--;
							else 
								printf("\nERROR\n");
						}
					}
					
					break;
				}
	
				case 2: {
					f = 1;
					
					while (f == 1 && end_check == 0) {
						num = take_number_matches();
						if (end_check == 0) {
							i = 1;
							if (check_correct_matches(mass, i, num))
								f--;
							else 
								printf("\nERROR\n");
						}
					}
					
					break;
				}
	
				case 3: {
					f = 1;
					
					while (f == 1 && end_check == 0) {
						num = take_number_matches();
						if (end_check == 0) {
							i = 2;
							if (check_correct_matches(mass, i, num))
								f--;
							else 
								printf("\nERROR\n");
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
			
			while (f == 1 && end_check == 0) {
				input = heap_selection();
				if (end_check == 0)
					f = heap_check(input, mass);
			}
	
			if (end_check == 0) { 
				
				switch (input) {
				
				case 1: {
					f = 1;
					
					while (f == 1 && end_check == 0) {
						num = take_number_matches();
						if (end_check == 0) {
							i = 0;
							if (check_correct_matches(mass, i, num))
								f--;
							else
								printf("\nERROR\n");
						}
					}
					
					break;
				}

				case 2: {
					f = 1;

					while (f == 1 && end_check == 0) {
						num = take_number_matches();
						if (end_check == 0) {
							i = 1;
							if (check_correct_matches(mass, i, num))
								f--;
							else
								printf("\nERROR\n");
						}
					}
					
					break;
				}

				case 3: {
					f = 1;
					
					while (f == 1 && end_check == 0) {
						num = take_number_matches();
						if (end_check == 0) {
							i = 2;
							if (check_correct_matches(mass, i, num))
								f--;
							else
								printf("\nERROR\n");
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
	if (end_quit == 1) {
		return 1;
	} else if (status == 0) {
		printf("n - quit, any key - continue\n");
		char end;
		end = mygetch();
		
		if (end == 'n') {
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
	end = mygetch();
	
	if (end == 'y') {
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
				set_score -> win_players1++;
				set_score -> loss_players2++;
				printf("Name: %s\t", names_players -> name_players1);
				printf("Count win: %d, loss: %d\n\n",
					set_score -> win_players1, set_score -> loss_players1);
			} else {
				set_score -> win_players2++;
				set_score -> loss_players1++;
				printf("Name: %s\t", names_players -> name_players2);
				printf("Count win: %d, loss: %d\n\n",
					set_score -> win_players2, set_score -> loss_players2);
			}
			
			end_check = 1;
		}
	} while (end_nim(names_players, set_score, 0) == 0);
	
	safe_score_nim(names_players, set_score);
}
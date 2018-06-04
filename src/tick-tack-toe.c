#include <stdio.h>
#include <stdlib.h>
#include "tick-tack-toe.h"

int status_game = 0;
int end_game = 1;
char space = ' ';

int mygetch()
{
	int k = 0;
	char ch;
	
	do {
		ch = getchar();
		
		if (ch != '\n') {
			k = 1;
		}
	} while (k == 0);
	
	while (getchar() != '\n');

	return ch;
}

void start_game_tick()
{
	name *names_players = malloc(sizeof(name));
	score *set_score = malloc(sizeof(score));
	enter_names(names_players, set_score);
	end_game = 0;
	status_game = 1;
	
	while (end_game == 0) {
		int number_move = 0;
		char ch[const_height][const_length] = {
		" | | ",
		" | | ",
		" | | "
		};
		
		while (check_win(ch) == 0 && status_game) {
			printf("the move of the %d player\n", (number_move % 2) + 1);
			char a[length_scanf_str];
			
			do {
				if (enter_coordinate(a) == -1)
				it_end(names_players, set_score, 1);
			} while (!check_correct_data(a, ch) && status_game);
			
			if (status_game) {
				past(a, ch, number_move);
				print_board(ch);
				number_move++;
			}
		}
		
		if (status_game) {
			if (check_win(ch) == 2)
				printf("Dead heat\n");
			else {
				printf("\nWin player %d\n", ((number_move - 1) % 2) + 1);
				if (((number_move - 1) % 2) + 1 == 1) {
					set_score->win_players1++;
					set_score->loss_players2++;
					printf("Name: %s\t", names_players -> name_players1);
					printf("Count win: %d, loss: %d\n\n",
						set_score -> win_players1, set_score -> loss_players1);
				} else {	
					set_score->win_players2++;
					set_score->loss_players1++;
					printf("Name: %s\t", names_players -> name_players2);
					printf("Count win: %d, loss: %d\n\n",
						set_score -> win_players2, set_score -> loss_players2);
				}
			}
	
			printf("n - quit, any key - continue\n");
			it_end(names_players, set_score, 0);
		}
	}
}

int enter_coordinate(char a[])
{
	int i, k = 0;
	for (i = 0; (i < 3 - 1) && k == 0; i++) {
		a[i] = getchar();
		
		if (a[i] == 'q')
			return -1;
		
		a[i + 1] = '\0';
		
		if (a[i] == '\n')
			k = 1;
	}
	
	if ((i >= 2) && k == 0)
		while(getchar() != '\n');
	
	printf("\n");
	
	return 0;
}

void print_board(char ch[][const_length])
{
	int i, j;
	for (i = 0; i < const_height - 1; ++i) {
		for (j = 0; j < const_length - 1; ++j)
			printf("%c", ch[i][j]);
		printf("\n");
	}
}

void it_end(name *names_players, score *score, int status)
{
	if (status == 0) {
		char end;
		end = mygetch();
		if (end == 'n') {
			system("clear");
			status_game = 0;
			end_game = 1;	
			safe_score(names_players, score);
		} else
			printf("\nRestart game\n\n");
	} else if (status == 1) {
		char end;
		printf("\nAre you sure you want to finish the game?\n");
		printf("If you sure press y, else press any key\n");
		end = mygetch();
		
		if (end == 'y') {
			system("clear");
			status_game = 0;
			end_game = 1;
			safe_score(names_players, score);
		}
	}
}

void enter_names(name *names_players, score *set_score)
{
	printf("Enter name for players 1\n");
	int i, k = 0;
	
	for (i = 0; (i < length_name - 1) && k == 0; i++){
		names_players -> name_players1[i] = getchar();
		names_players -> name_players1[i + 1] = '\0';
		
		if (names_players -> name_players1[i] == '\n') {
			if (names_players -> name_players1[0] != '\n'
					&& names_players -> name_players1[0] != '\0') {
				k = 1;
				printf("\n");
			} else
				i--;
		}
	}
	
	if (i >= length_name - 1)
		while (getchar() != '\n');

	printf("Enter name for players 2\n");
	k=0;
	
	for (i = 0; (i < length_name - 1) && k == 0; i++) {
		names_players -> name_players2[i] = getchar();
		names_players -> name_players2[i + 1] = '\0';
		
		if (names_players -> name_players2[i] == '\n') {
			if (names_players -> name_players2[0] != '\n'
					&& names_players -> name_players2[0] != '\0') {
				k = 1;
				printf("\n");
			} else
				i--;
		}
	}
	
	if (i >= length_name - 1)
		while (getchar() != '\n');

	set_score -> win_players1 = 0;
	set_score -> loss_players1 = 0;
	set_score -> win_players2 = 0;
	set_score -> loss_players2 = 0;
}

void past(char *a, char ch[][const_length], int number)
{
	if (number % 2 == 0) {
		if (a[1] - '1' == 0)
			ch[a[0] - '1'][a[1] - '1'] = 'x';
		else if (a[1] - '1' == 1)
			ch[a[0] - '1'][a[1] - '1' + 1] = 'x';
		else if (a[1] - '1' == 2)
			ch[a[0] - '1'][a[1] - '1' + 2] = 'x';
	} else {
		if (a[1] - '0' == 1)
			ch[a[0] - '1'][a[1] - '1'] = 'o';
		else if (a[1] - '0' == 2)
			ch[a[0] - '1'][a[1] - '1' + 1] = 'o';
		else if (a[1] - '0' == 3)
			ch[a[0] - '1'][a[1] - '1' + 2] = 'o';		
	}
}

int check_correct_data(char* a, char ch[][const_length])
{
	if ((a[0] >= '1' && a[0] <= '3') && (a[1] >= '1' && a[1] <= '3')) {
		
		if (a[1] - '1' == 0 && ch[a[0] - '1'][a[1] - '1'] == space)
			return 1;
		else if (a[1] - '1' == 1 && ch[a[0] - '1'][a[1] - '1' + 1] == space)
			return 1;
		else if (a[1] - '1' == 2 && ch[a[0] - '1'][a[1] - '1' + 2] == space)
			return 1;
		
		printf("The cage is not empty, Enter data again\n");
		return 0;
	}
	
	printf("\nError, Enter correct data\n");
	return 0;
}

void copy_struct_to_string(char buff1[], char buff2[], name  *names_players)
{
	int i, j = 0, k = 0;
	
	for (i =0; i < length_name - 1; i++ ) {
		
		if (names_players -> name_players1[i] != '\0' && k == 0) {
			buff1[i] = names_players -> name_players1[i];
			buff1[i + 1] = '\0';
		} else
			k = 1;
		
		if (names_players -> name_players2[i] != '\0' && j == 0) {
			buff2[i] = names_players -> name_players2[i];
			buff2[i + 1] = '\0';
		} else
			j = 1;
	}
}

void copy_string(char buff1[], char buff2[])
{
	int i;
	
	for (i =0; (i < length_name - 1) && buff2[i] != '\0'; i++ ) {
		buff1[i] = buff2[i];
		buff1[i + 1] = '\0';
	}
}


int equal_string(char buff1[], char buff2[])
{
	int i, k = 0;
	
	for (i =0; ( i < length_name - 1) && k == 0 
			&& (buff1[i] != '\0' && buff2[i]!= '\0'); i++ ) {
		if ( !(buff1[i] == buff2[i]) && k == 0)
			return 0;
	}
	
	return 1;
}

int count_string_tick()
{
	FILE *read_score;
	char name[length_name];
	int win, loss, i = 0;
	
	if ((read_score = fopen("score_tick.txt", "rt")) != NULL) {
		while (!feof(read_score)) {
			fscanf(read_score, "%s%d%d", name, &win, &loss);
			i++;
		}
		
		fclose(read_score);
		return i - 1;
	}
	
	return i;
}

void safe_score(name *names_players, score *score)
{
	char buff[max_safe_score][length_name];
	int win[max_safe_score], loss[max_safe_score], i, t;
	int find_players[] = {0, 0};
	char buff1[length_name], buff2[length_name];
	FILE *safe_score;
	t = count_string_tick();
	i = 0;
	
	if ((safe_score = fopen("score_tick.txt", "rt")) != NULL) {
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
			win[t] += score->win_players1;
			loss[t] += score->loss_players1;
			find_players[0]++;
		}
		
		if (equal_string(buff[t], buff2) == 1) {
			win[t] += score->win_players2;
			loss[t] += score->loss_players2;
			find_players[1]++;
		}
	}

	if (find_players[0] == 0) {
		copy_string( buff[i], buff1);
		win[i] = score->win_players1;
		loss[i] = score->loss_players1;
		i++;
	}

	if (find_players[1] == 0) {
		copy_string( buff[i], buff2);
		win[i] = score->win_players2;
		loss[i] = score->loss_players2;
		i++;
	}
	
	sort_top(buff, win, loss, i);
	
	if ((safe_score = fopen("score_tick.txt", "wt")) != NULL) {
		for (t = 0; t < i; t++ ) {
			fprintf(safe_score, "%s %d %d\n", buff[t], win[t], loss[t]);	
		}
	
		fclose(safe_score);
	}
}

void sort_top(char buff[][length_name], int win[], int loss[], int count_name)
{
	char buff_copy[length_name];
	int win_copy, loss_copy;
	int i, j, max;
	
	for (i = 0; i < count_name; i++) {
		for (j = i; j < count_name; j++) {
			max = win[i];
			
			if (max < win[j]) {
				copy_string( buff_copy, buff[i]);
				copy_string( buff[i], buff[j]);
				copy_string( buff[j], buff_copy);
				win_copy = win[i];
				win[i] = win[j];
				win[j] = win_copy;
				loss_copy = loss[i];
				loss[i] = loss[j];
				loss[j] = loss_copy;
			}
		}
	}
}

int check_win(char ch[][const_length])
{
	int i,j=0, num=0;
	
	for (i=0; i<const_height - 1; i++) {
		if ((ch[i][j] == 'x' && ch[i][j+2] == 'x' && ch[i][j+4] == 'x')
				|| (ch[i][j] == 'o' && ch[i][j+2] == 'o' && ch[i][j+4] == 'o'))
			return 1;
	}
	
	for (j=0, i=0; j<const_length - 1; j+=2) {
		if ((ch[i][j] == 'x' && ch[i+1][j] == 'x' && ch[i+2][j] == 'x')
				|| (ch[i][j] == 'o' && ch[i+1][j] == 'o' && ch[i+2][j] == 'o'))
			return 1;
	}
	
	if ((ch[0][0] == 'x' && ch[1][2] == 'x' && ch[2][4] == 'x')
			|| (ch[0][0] == 'o' && ch[1][2] == 'o' && ch[2][4] == 'o')) 
		return 1;
	else if ((ch[0][4] == 'x' && ch[1][2] == 'x' && ch[2][0] == 'x')
			|| (ch[0][4] == 'o' && ch[1][2] == 'o' && ch[2][0] == 'o'))
		return 1;

	for (i=0; i<const_height - 1; i++) {
		if ((ch[i][j] != space && ch[i][j+2] != space && ch[i][j+4] != space))
			num++;
		if (num == 3)
			return 2;
	}
	
	return 0;
}
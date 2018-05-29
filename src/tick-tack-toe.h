#ifndef TICK_H
#define TICK_H
typedef struct{

	char name_players1[16];
	char name_players2[16];
} name;

typedef struct{
	int win_players1;
	int loss_players1;
	int win_players2;
	int loss_players2;
} score;

#define const_height 4
#define const_length 6
#define length_scanf_str 3

int check_win(char ch[][const_length]);
void start_game();
void past(char*a, char ch[][const_length], int number);
int check_correct_data(char* a, char ch[][const_length]);
void enter_names(name *names_players, score *set_score);
void it_end();
void print_board(char ch[][const_length]);
void enter_coordinate(char a[]);
#endif
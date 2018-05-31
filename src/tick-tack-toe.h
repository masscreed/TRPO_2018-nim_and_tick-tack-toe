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
#define length_name 16

void print_top_tick();
int check_win(char ch[][const_length]);
void start_game_tick();
void past(char*a, char ch[][const_length], int number);
int check_correct_data(char* a, char ch[][const_length]);
void enter_names(name *names_players, score *set_score);
void it_end(name *names_players, score *score, int status);
void print_board(char ch[][const_length]);
int enter_coordinate(char a[]);
void safe_score(name *names_players, score *score);
#endif
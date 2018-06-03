#ifndef NIM_H
#define NIM_H

void mass_input(int mass[3]);
void mass_output(int mass[3]);
int heap_selection();
int heap_check(int input, int mass[3]);
int take_number_matches();
void heap_change(int* mass, int i, int num);
int check_correct_matches(int* mass, int i, int num);
int count_string_nim();
void safe_score_nim(name *names_players, score *score);
int mechanics_of_the_game (int mass[3]);
void start_game_nim();
int end_nim (name *names_players, score *score, int status);
int end_nim_quit();
void print_top_nim();

#endif
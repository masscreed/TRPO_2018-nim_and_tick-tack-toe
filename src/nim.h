#ifndef NIM_H
#define NIM_H

void mass_input(int mass[3]);
void mass_output(int mass[3]);
int heap_selection();
int heap_check(int input, int mass[3], int f);
int take_number_matches();
int* heap_change(int* mass, int i, int num);
int mechanics_of_the_game (int mass[3]);
void start_game_nim();
int end_nim (name *names_players, score *score, int status);
int end_nim_quit();

#endif
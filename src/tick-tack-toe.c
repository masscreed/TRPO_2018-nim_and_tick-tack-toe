#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tick-tack-toe.h"


int status_game = 0;
int end_game = 1;
char space = ' ';

int main() 
{
	start_game();
    return 0;
}

void start_game()
{
	name *names_players = malloc(sizeof(name));
	score *set_score = malloc(sizeof(score));
	enter_names(names_players, set_score);
	end_game = 0;
	status_game = 1;
	while(end_game == 0)
	{
		int number_move=0;
		char ch[const_height][const_length] = {
		" | | ",
		" | | ",
		" | | "
		};
		while (check_win(ch) == 0)
		{
			printf("the move of the %d player\n", (number_move % 2) + 1);
			char a[length_scanf_str];
			do
			{
				enter_coordinate(a);
			}
			while(!check_correct_data(a, ch));
			past(a, ch, number_move);
			print_board(ch);
			number_move++;
		}
		if (check_win(ch) == 2)
			printf("Dead heat\n");
		else
		{
			printf("\nWin player %d\n", ((number_move - 1) % 2) + 1);
			if(((number_move - 1) % 2) + 1 == 1)
			{
				set_score->win_players1++;
				set_score->loss_players2++;
				printf("Name: %s\t", names_players->name_players1);
				printf("Count win: %d, loss: %d\n\n", set_score->win_players1, set_score->loss_players1);
			}
			else
			{	
				set_score->win_players2++;
				set_score->loss_players1++;
				printf("Name: %s\t", names_players->name_players2);
				printf("Count win: %d, loss: %d\n\n", set_score->win_players2, set_score->loss_players2);
			}
		}
		printf("Enter n if you do not want to continue playing, else press any key\n");
		it_end();
	}
}

void enter_coordinate(char a[])
{
	int i;
	for(i = 0; i < 3 - 1; i++)
	{
		a[i] = getche();
		a[i + 1] = '\0';
		if(a[i] == '\n')
			i++;
	}
	printf("\n");
}

void print_board(char ch[][const_length])
{
	int i, j;
	for (i = 0; i < const_height - 1; ++i)
	{
		for (j = 0; j < const_length - 1; ++j)
			printf("%c", ch[i][j]);
		printf("\n");
	}
}

void it_end()
{
	char end;
	end = getche();
	if( end == 'n')
	{
		printf("\nEnd game\n\n");
		status_game = 0;
		end_game = 1;	
	}
	else
		printf("\nRestart game\n\n");
}

void enter_names(name *names_players, score *set_score)
{
	printf("Enter name for players 1\n");
	int i, k=0;
	for(i = 0; (i < 16 - 1) && k == 0; i++)
	{
		names_players->name_players1[i] = getchar();
		if(names_players->name_players1[i] == '\n')
		{
			k = 1;
			printf("\n");
		}
		names_players->name_players1[i + 1] = '\0';
	}
	printf("Name: %s\n", names_players->name_players1);
	if( i >= 15)
		while(getchar() != '\n');

	printf("Enter name for players 2\n");
	k=0;
	for(i = 0; (i < 16 - 1) && k == 0; i++)
	{
		names_players->name_players2[i] = getchar();
		if(names_players->name_players2[i] == '\n')
			k = 1;
		names_players->name_players2[i + 1] = '\0';
	}
	printf("Name: %s\n", names_players->name_players2);
	if( i >= 15)
		while(getchar() != '\n');

	set_score->win_players1 = 0;
	set_score->loss_players1 = 0;
	set_score->win_players2 = 0;
	set_score->loss_players2 = 0;
}

void past(char *a, char ch[][const_length], int number)
{
	if ( number % 2 == 0)
	{
		if(a[1] - '1' == 0)
			ch[a[0] - '1'][a[1] - '1'] = 'x';
		else if(a[1] - '1' == 1)
			ch[a[0] - '1'][a[1] - '1' + 1] = 'x';
		else if(a[1] - '1' == 2)
			ch[a[0] - '1'][a[1] - '1' + 2] = 'x';
	}
	else
	{
		if(a[1] - '0' == 1)
			ch[a[0] - '1'][a[1] - '1'] = 'o';
		else if(a[1] - '0' == 2)
			ch[a[0] - '1'][a[1] - '1' + 1] = 'o';
		else if(a[1] - '0' == 3)
			ch[a[0] - '1'][a[1] - '1' + 2] = 'o';		
	}
 }
 
int check_correct_data(char* a, char ch[][const_length])
 {
	if( (a[0]>= '1' && a[0] <= '3') && (a[1]>= '1' && a[1] <= '3' ) )
	{
		if(a[1] - '1' == 0 && ch[a[0]-'1'][a[1]-'1'] == space)
			return 1;
		else if(a[1] - '1' == 1 && ch[a[0]-'1'][a[1]-'1' + 1] == space)
			return 1;
		else if(a[1] - '1' == 2 && ch[a[0]-'1'][a[1]-'1' + 2] == space)
			return 1;
		printf("The cage is not empty, Enter data again\n");
		return 0;
	}
	printf("Error, Enter correct data\n");
	return 0;
 }
 
int check_win(char ch[][const_length])
{
	int i,j=0, num=0;
	for(i=0; i<const_height - 1; i++)
	{
		if( (ch[i][j] == 'x' && ch[i][j+2] == 'x' && ch[i][j+4] == 'x') 
			|| (ch[i][j] == 'o' && ch[i][j+2] == 'o' && ch[i][j+4] == 'o') )
				return 1;
	}
	for(j=0, i=0; j<const_length - 1; j+=2)
	{
		if( (ch[i][j] == 'x' && ch[i+1][j] == 'x' && ch[i+2][j] == 'x') 
			|| (ch[i][j] == 'o' && ch[i+1][j] == 'o' && ch[i+2][j] == 'o') )
			return 1;
	}
	if( (ch[0][0] == 'x' && ch[1][2] == 'x' && ch[2][4] == 'x') 
		|| (ch[0][0] == 'o' && ch[1][2] == 'o' && ch[2][4] == 'o') ) 
		return 1;
	else if( (ch[0][4] == 'x' && ch[1][2] == 'x' && ch[2][0] == 'x') 
		|| (ch[0][4] == 'o' && ch[1][2] == 'o' && ch[2][0] == 'o') )
		return 1;
		
	for(i=0; i<const_height - 1; i++)
	{
		if( (ch[i][j] != space && ch[i][j+2] != space && ch[i][j+4] != space) )
			num++;
		if(num == 3)
			return 2;
	}
	return 0;
}
#include <stdio.h>

#define const_height 4
#define const_length 6
#define length_scanf_str 3
int status_game = 0;
int check_data(char ch[][const_length]);
int check_win(char ch[][const_length]);
void start_game();
void past(char*a, char ch[][const_length], int number);
int check_correct_data(char* a, char ch[][const_length]);

char space = ' ';
int main() 
{
	start_game();
    return 0;
}

void start_game()
{
	status_game = 1;
	int i, j;
	int number_move=0;
	char ch[const_height][const_length] = {
	" | | ",
	" | | ",
	" | | "
    };
	while (!check_win(ch))
	{
		char a[length_scanf_str];
		scanf("%s", a);
		while(!check_correct_data(a, ch))
			scanf("%s", a);
		past(a, ch, number_move);				// Фунуция выполняющая ход игрока
		for (i = 0; i < const_height - 1; ++i)
		{
			for (j = 0; j < const_length - 1; ++j)
				printf("%c", ch[i][j]);
			printf("\n");
		}
		number_move++;
	}
	printf("Win player %d\n", ((number_move - 1) % 2) + 1);
}

void past(char*a, char ch[][const_length], int number)
{
/* 	if((a[1]-'0')%2!=0)
		ch[a[0]-'1'][a[1]-'0'-1] = 'x';
	else if((a[1]-'0')%2==0)
		ch[a[0]-'1'][a[1]-'0'] = 'x';
 */
	/*if((a[1]-'0')%2==0)
		a[1]=+1;
	ch[a[0]-'1'][a[1]-'0'-1] = 'x';**/
	//printf("%d - %d \n", a[0]-'0', a[1]-'0');
	if ( number % 2 == 0)
	{		
		if(a[1]-'0'==1)
			ch[a[0]-'1'][a[1] - '1'] = 'x';
		else if ((a[1]-'0')%2==0)
			ch[a[0]-'1'][a[1] - '1' +1 ] = 'x';
		else if ((a[1]-'0')%2!=0)
			ch[a[0]-'1'][a[1] - '1' + 2] = 'x';
	}
	else
	{
		if(a[1]-'0'==1)
			ch[a[0] - '1'][a[1] - '1'] = 'o';
		else if ((a[1]-'0')%2==0)
			ch[a[0]-'1'][a[1]-'1' + 1] = 'o';
		else if ((a[1]-'0')%2!=0)
			ch[a[0]-'1'][a[1]-'0'+1] = 'o';
	}
 }
 
int check_correct_data(char* a, char ch[][const_length])
 {
	if( (a[0]>= '1' && a[0] <= '3') && (a[1]>= '1' && a[1] <= '3' ) )
	{
		if(a[1] - '1' == 0 && ch[a[0]-'1'][a[1] - '1'] == space)
			return 1;
		else if ( (a[1] - '0') % 2 == 0 &&
			ch[a[0] - '1'][a[1] - '1' + 1 ] == space) 
			return 1;
		else if ( (a[1] - '0') % 2 != 0 && 
			ch[a[0]-'1'][a[1] - '1' + 2] == space)
			return 1;
		printf("The cage is not empty, Enter data again\n");
		return 0;
	}
	printf("Error, Enter correct data\n");
	return 0;
 }
 
int check_data(char ch[][const_length])
{
	return 0;
}
 
int check_win(char ch[][const_length])
{
	int i,j=0;
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
		
	return 0;
}

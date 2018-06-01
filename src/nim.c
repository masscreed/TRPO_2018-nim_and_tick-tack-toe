#include<stdio.h>

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
	
	while (n == 0) {
		printf("\nSelect a pile\n");
		gets(str);
		if ( isdigit(str[0]) ) {
			input = atoi (str);
			n++;
		} else {
			printf("ERROR");
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
	
	while (k == 0) {
		printf("\nHow many matches to take?\n");
		gets(str);
		if ( isdigit(str[0]) ) {
			num = atoi (str);
			k++;
		} else {
			printf("ERROR");
		}
	}
	
	return num;
}

int* heap_change(int* mass, int i, int num) { //подсчет кучки после take_number_matches
	mass[i] = mass[i] - num;
	
	return mass[i];
}

void mechanics_of_the_game (int mass[3]) { //механика игры
	int num, input; //num - количество взятых спичек, input - выбранная кучка
	int k = 1, f, i; //k - проверка на очередь игрока, f - проверка на правельность введеного значения
	
	while ( mass[0] > 0 || mass[1] > 0 || mass[2] > 0) {
		if ( k == 1) {
			printf("\nPlayer # 1 is walking\n");
			f = 1;
			
			while ( f == 1 ) {
				input = heap_selection();
				f = heap_check(input, mass, f);
			}
			
			switch ( input ) {
				case 1: {
					f = 1;
					while ( f == 1 ) {
						
						num = take_number_matches();
						
						if (num <= mass[0]) {
							i = 0;
							mass[0] = heap_change(mass, i, num);
							mass_output(mass);
							f--;
						} else {
							printf("\nERROR\n");
						}
					}
					break;
				}
				case 2: {
					f = 1;
					while ( f == 1 ) {
						
						num = take_number_matches();
						
						if (num <= mass[1]) {
							i = 1;
							mass[1] = heap_change(mass, i, num);
							mass_output(mass);
							f--;
						} else {
							printf("\nERROR\n");
						}
					}
					break;
				}
				case 3: {
					f = 1;
					while ( f == 1 ) {
						
						num = take_number_matches();
						
						if (num <= mass[2]) {
							i = 2;
							mass[2] = heap_change(mass, i, num);
							mass_output(mass);
							f--;
						} else {
							printf("\nERROR\n");
						}
					}
					break;
				}
			}
			k++;
		} else {
			printf("\nPlayer # 2 is walking\n");
			f = 1;
			while ( f == 1 ) {
				input = heap_selection();
				f = heap_check(input, mass, f);
			}
			
			switch ( input ) {
				case 1: {
					f = 1;
					while ( f == 1 ) {
						
						num = take_number_matches();
						
						if (num <= mass[0]) {
							i = 0;
							mass[0] = heap_change(mass, i, num);
							mass_output(mass);
							f--;
						} else {
							printf("\nERROR\n");
						}
					}
					break;
				}
				case 2: {
					f = 1;
					while ( f == 1 ) {
						
						num = take_number_matches();
						
						if (num <= mass[1]) {
							i = 1;
							mass[1] = heap_change(mass, i, num);
							mass_output(mass);
							f--;
						} else {
							printf("\nERROR\n");
						}
					}
					break;
				}
				case 3: {
					f = 1;
					while ( f == 1 ) {
						
						num = take_number_matches();
						
						if (num <= mass[2]) {
							i = 2;
							mass[2] = heap_change(mass, i, num);
							mass_output(mass);
							f--;
						} else {
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

int main () {
	int mass[3];
	
	mass_input(mass);
	
	mass_output(mass);
	
	mechanics_of_the_game(mass);
	
	printf("\nYOU WIN\n");
	return 0;
}
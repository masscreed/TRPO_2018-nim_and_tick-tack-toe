#include<stdio.h>

void print_mass(int mass[3])
{
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

int main()
{
	int mass[3];
	int n, input;
	int k = 1, f;
	
	printf("\nEnter the number of matches in the first pile\n");
	scanf("%d", &mass[0]);
	printf("\nEnter the number of matches in the second pile\n");
	scanf("%d", &mass[1]);
	printf("\nEnter the number of matches in the third pile\n");
	scanf("%d", &mass[2]);
	
	print_mass(mass);
	
	while ( mass[0] > 0 || mass[1] > 0 || mass[2] > 0) {
		if ( k == 1) {
			printf("\nPlayer # 1 is walking\n");
			f = 1;
			while ( f == 1 ) {
				printf("\nSelect a pile\n");
				scanf("%d", &input);
				if ( input >= 1 && input <= 3 ) {
					if ( mass[input-1] > 0 )
						f--;
					else
						printf("\nERROR\n");
				} else 
					printf("\nERROR\n");
			}
			switch ( input ) {
				case 1: {
					f = 1;
					while ( f == 1 ) {
						printf("\nHow many matches to take?\n");
						scanf("%d", &n);
						if (n <= mass[0]) {
							mass[0] = mass[0] - n;
							print_mass(mass);
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
						printf("\nHow many matches to take?\n");
						scanf("%d", &n);
						if (n <= mass[1]) {
							mass[1] = mass[1] - n;
							print_mass(mass);
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
						printf("\nHow many matches to take?\n");
						scanf("%d", &n);
						if (n <= mass[2]) {
							mass[2] = mass[2] - n;
							print_mass(mass);
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
				printf("\nSelect a pile\n");
				scanf("%d", &input);
				if ( input >= 1 && input <= 3 ) {
					if ( mass[input-1] > 0 )
						f--;
					else
						printf("\nERROR\n");
				} else
					printf("\nERROR\n");
			}
			switch ( input ) {
				case 1: {
					f = 1;
					while ( f == 1 ) {
						printf("\nHow many matches to take?\n");
						scanf("%d", &n);
						if (n <= mass[0]) {
							mass[0] = mass[0] - n;
							print_mass(mass);
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
						printf("\nHow many matches to take?\n");
						scanf("%d", &n);
						if (n <= mass[1]) {
							mass[1] = mass[1] - n;
							print_mass(mass);
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
						printf("\nHow many matches to take?\n");
						scanf("%d", &n);
						if (n <= mass[2]) {
							mass[2] = mass[2] - n;
							print_mass(mass);
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
	
	printf("\nYOU WON\n");
	return 0;
}

#include <stdio.h>
#define MAX_INPUT 20
#include <string.h>
#include <stdlib.h>

char backchar(char array[MAX_INPUT][MAX_INPUT], char input1, int input, char anykey);
void pointer(char array[MAX_INPUT][MAX_INPUT], int row, int column, int n, char cha);
void vertical(char array[MAX_INPUT][MAX_INPUT],int row,int column,int n,char cha);
void horizontal(char array[MAX_INPUT][MAX_INPUT], int row,int column,int n,char cha);
void printarray(char array[MAX_INPUT][MAX_INPUT], int input);

int main(void)
{
	int input;
	int run = 1;
	int run1 = 1;
	int i,j;
	char input1;
	char anykey;
	char command;
	char cha;
	int row, column, n;
	char array[MAX_INPUT][MAX_INPUT] = {};
	
	while(run)
	{	
		printf("How big is the array? (Enter a value between 1 and 20) ");
		scanf(" %d", &input);
		
		if ( input >= 0 && input <= MAX_INPUT)
		{	
			printf("What is the background Character? ");
			scanf(" %c", &input1);
			backchar(array,input1, input, anykey);
			printarray(array, input);
			
		
			while(run1)
			{
				printf("Enter draw command (enter Q to quit) ");
				scanf(" %c(%d,%d,%d)%c", &command, &row, &column, &n, &cha);
				
				if ((command == 'Q') || (command == 'q'))
				{
					printf("\n");
					return run1 = 0;
				}	
				
				else if (((command == 'P') || (command == 'p')) && (n >= 0 && n == 1) && (row <= input) && (column <= input))
				{
					printf("\n");
					pointer(array, row, column, n, cha);
					printarray(array, input);
				}
				
				else if (((command == 'H') || (command == 'h')) && ((n <= input - column) && (n > 1)) && (row <= input) && (column <= input))
				{
					printf("\n");
					horizontal(array, row, column, n, cha);
					printarray(array, input);
				}
				
				else if (((command == 'V') || (command == 'v')) && ((n <= input - row) && (n > 1)) && (row <= input) && (column <= input))
				{
					printf("\n");
					vertical(array, row, column, n, cha);
					printarray(array, input);
				}
				
				else if (!((command == 'P') || (command == 'p') || (command == 'V') ||(command == 'v') ||(command == 'H') ||(command == 'h' ) ||(command == 'q') ||(command == 'Q' )))
				{
					
					printf("\nThat draw command is unknown\n\n");
					printarray(array, input);
				}
				
				else
				{
					printf("\nThat draw command is out of range\n\n");
					printarray(array, input);
				}
			}
			
			return run = 0;
		}	
	
		else
		{
			printf("That value is outside of the max bounds of the array. Please reenter");
			printf("\n\n");
		}
	}
}

char backchar(char array[MAX_INPUT][MAX_INPUT], char input1, int input, char anykey)
{
	printf("\n\n\n");
	
	int i,j;
	
	for(i = 0; i < input; ++i)
	{
		for(j=0;j < input; j++)
		{
			array[i][j] =input1;
		}
	}
	
printf("Draw commands start with");
	printf("\n\n\n");
	printf("\t");
	printf("P for a single point");
	printf("\n");
	printf("\t");
	printf("H for a horizontal line");
	printf("\n");
	printf("\t");
	printf("V for a vertical line");
	printf("\n\n\n");
	printf("After the P/V/H, enter a row,col coordinate and the number of spots to mark\n\n");
	printf("enclosed in () and separated by commans and then the character for the mark.\n\n");
	printf("'X' will be used if a mark is not entered. For example,");
	printf("\n\n");
	printf("\t");
	printf("P(2,3,1)*\t start at point 2,3 in the array and mark one spot\n");
	printf("\t\t\t with a *. For P, the 3rd parameter is ignored.\n\n");
	printf("\t");
	printf("V(1,2,3)$\t start at point 1,2 in the array and mark the next\n");
	printf("\t\t\t 3 spots to the right with $\n\n");
	printf("\t");		
	printf("H(4,6,7)#\t start at point 4,6 in the array and mark the next\n");
	printf("\t\t\t 7 spots down from the current position with #\n\n\n");
	printf("Coordinates out of range and lines drawn past the borders are not allowed.\n\n\n");		
	printf("Enter Q at the draw command prompt to quit\n\n\n");
	printf("Press <ENTER> to continue\t");	
	getchar();	
	anykey = getchar();
	printf("\n\n\n");	
	
	printf("\n");	

return input1;	
}

void pointer(char array[MAX_INPUT][MAX_INPUT], int row, int column, int n, char cha)
{	
	array[row][column] = cha;	
}

void vertical(char array[MAX_INPUT][MAX_INPUT],int row,int column,int n,char cha)
{
	int i,j;
	int z = n+1;
	
	for(i = 0; i < z; ++i)
	{
		array[(row+i)][column] = cha;
	}	
}



void horizontal(char array[MAX_INPUT][MAX_INPUT], int row,int column,int n,char cha)
{
	int i,j;
	int z = n+1;
	
	for(i = 0; i < z ; ++i)
	{
		array[row][(column+i)] = cha;
	}	
	
}

void printarray(char array[MAX_INPUT][MAX_INPUT], int input)
{
	int i;
	int j;
	
	for(i = 0; i < input; ++i)
	{
		for(j=0;j < input; j++)
		{
			printf(" %c ", array[i][j]);
		}
		
		printf("\n\n");
	}
	
}



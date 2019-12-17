

#include "ListLib.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define DATA 10000;

void AddNode(char NewLetter, char NewDrawComm[MAX], node **LinkedListHead)
{
	node *TempPtr, *NewNode;
	
	NewNode = malloc(sizeof(node));
	NewNode->drawchar = NewLetter;
	strcpy(NewNode->DrawCommand,NewDrawComm);
	NewNode->next_ptr = NULL;
	
	if(*LinkedListHead == NULL)
	{
		*LinkedListHead = NewNode;
	}	
	
	else
	{
		TempPtr = *LinkedListHead;
		
		while(TempPtr->next_ptr != NULL)
			TempPtr = TempPtr ->next_ptr;
		
		TempPtr->next_ptr = NewNode;
	}	
}

void SearchNode(char NewLetter, char CommCompare[MAX], node **marker)
{
	node *TempPtr, *NewNode;
	
	TempPtr = *marker;
	
	while (TempPtr != NULL)
	{
		if(TempPtr->drawchar == NewLetter)
		{
			strcpy(CommCompare, TempPtr->DrawCommand);
			*marker = TempPtr->next_ptr;
			return;
		}	
		
		TempPtr = TempPtr ->next_ptr;
	}	
	
	*marker = TempPtr;
}

void PrintArray(char array[][MAX])
{
	int a, b;
	
	for(a =0; a<MAX; a++)
	{	
		for(b = 0; b<MAX; b++)
		{
			printf(" %c ", array[a][b]);
		}	
		printf("\n\n");
	}
}

void DrawCMD(char drawcmd, char inputarray[][MAX], int row, int column, int step, char cha, int cycle)
{
	int check = islower(drawcmd);
	int check1 = isdigit(drawcmd);
	int check2 = ispunct(drawcmd);
	int check3 = isspace(drawcmd);
	int check4 = isspace(cha);
	int check5 = isalpha(row);
	int check6 = ispunct(row);
	int check7 = isalpha(column);
	int check8 = ispunct(column);
	int check9 = isalpha(step);
	int check10 = ispunct(step);
	
	if(check|| check1|| check2||  check3|| check4|| check5|| check6 || check7 || check8 ||check9 || check10)
	{
		printf("\nInvalid character(s) in draw command line or pipe delimiter, check your input file: \n\n");
		printf("Note: use correct syntax for draw command. e.g. (alpha)|(#,#,#)(char) \n\n");
		printf("Program Exiting \n\n");
		printf("\n\n");
		exit(0);
	}
	
	int i = 0;
	int j = 0;
	
	if(cycle == 1)
		column= column+7;
	
	else if (cycle ==2)
		column=column+14;
	
	if(cha =='\n')
	{
		printf("\nInvalid character in draw command line (last insert char), check your input file:\n\n");
		printf("Program Exiting");
		printf("\n\n");
		exit(0);
	}

	if(drawcmd == 'H')
	{
		for(i=0;i<step;i++)
		{
			inputarray[row][column+i] = cha;
		}	
		
	}	
	
	else if (drawcmd == 'V')
	{
		for(j = 0; j<step; j++)
		{
			inputarray[row+j][column] = cha;
		}	
	
	}

	else if(drawcmd == 'P')
	{
		inputarray[row][column] = cha;
	
	}	
	
	else
	{
		printf("\nInvalid character(s) found input:\n\n");
		printf("Possible Error 1: Character(s) requested to draw does not exist in your input file.\n\n");
		printf("Possible Error 2: More than 1 character inputted in background character, please input only 1 character.\n\n");
		printf("Program Exiting");
		printf("\n\n");
		exit(0);
	}	
}


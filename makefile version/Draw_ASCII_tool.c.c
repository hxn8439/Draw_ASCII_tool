

#include "ListLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define DATA 10000;

int main(int argc, char *argv[])
{
	node *LinkedListHead = NULL;
	node *marker = NULL;
	char *token;
	char delimiter[MAX] = "|";
	char FileName[MAX];
	char UserStringInput[3];
	char FileStringInput[MAX];
	char DrawCommand[MAX];
	char inputarray[MAX][MAX];
	char CommCompare[MAX];
	char BackGroundChar;
	char Letter;
	char DrawChar;
	char cha;
	int row,column,step;
	int i,j;
	
	printf("\nEnter a background character to print: ");
	scanf("%c", &BackGroundChar);
	
	if((BackGroundChar == '\n'))
	{
		printf("\nInvalid background character input, character must not be an escape sequence.\n\n");
		printf("Program exiting\n\n");
		exit(0);
	}
	
	printf("\nPlease enter 1-3 characters ");
	scanf("%s", UserStringInput);
	getchar();
	printf("\n");
	
	int StringLength = (strlen(UserStringInput));
	
	if((StringLength > 3) || (StringLength = 0))
	{
		printf("Invalid characters input, characters must be at length between 1 to 3.\n\n");
		printf("Program exiting\n\n");
		exit(0);
	}	
	
	for(i = 0; i<3; i++)
	{
		UserStringInput[i] = toupper(UserStringInput[i]);
	}	
	
	for(i = 0; i<MAX; i++)
	{
		for(j =0; j<MAX; j++)
		{
			inputarray[i][j] = BackGroundChar;
		}	
	}	
	
	
	FILE *myfile; 
	strcpy(FileName,argv[1]);
	myfile = fopen(FileName, "r");
	
	while(fgets(FileStringInput, MAX-1, myfile) != NULL)
	{
		if(ferror(myfile))
		{	
			perror ("Error");
		}
		token = strtok(FileStringInput, delimiter);
		Letter = *token;
		token = strtok(NULL, delimiter);
		strcpy(DrawCommand, token);
		AddNode(Letter, DrawCommand, &LinkedListHead);
		
	}	
	
	for(i = 0; i<strlen(UserStringInput); i++)
	{
		marker = LinkedListHead;
		while(marker != NULL)
		{
			SearchNode(UserStringInput[i], CommCompare, &marker);
			sscanf(CommCompare,"%c(%d,%d,%d)%c", &DrawChar, &row, &column, &step, &cha);
			DrawCMD(DrawChar, inputarray, row,column,step,cha, i);
		}	
	}	
	
	PrintArray(inputarray);
	printf("\n");
	
	fclose(myfile);
	
	return 0;
}


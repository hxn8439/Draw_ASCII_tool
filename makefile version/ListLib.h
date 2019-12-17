


#ifndef _LISTLIB_H 
#define _LISTLIB_H
#define MAX 20

typedef struct node
{
	char drawchar;
	char DrawCommand[MAX];
	struct node *next_ptr;
	
}node;

void AddNode(char NewLetter, char NewDrawComm[MAX], node **LinkedListHead);
void SearchNode(char NewLetter, char CommCompare[MAX], node **marker);
void DrawCMD(char drawcmd, char inputarray[][MAX], int row, int column, int step, char cha, int cycle);
void PrintArray(char array[][MAX]);

#endif


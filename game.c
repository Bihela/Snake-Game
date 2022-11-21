#include<stdlib.h>
#include<stdio.h>
#include"game.h"

void game(char fName[30])
{
    int row, col, i;
    int **mapArr;
    int ***pArray = &mapArr;
    int *pRow = &row;
    int *pCol = &col;
    
    getFileMetadata(pArray, pRow, pCol, fName);
    control(mapArr, pRow, pCol);
    for(i=0; i< row; i++)
    {
        free(mapArr[i]);
        mapArr[i] = NULL;
    }
}
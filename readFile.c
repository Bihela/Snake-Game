#include<stdlib.h>
#include <stdio.h>
#include"readFile.h"

void getFileMetadata(int ***pArray, int *pRow, int *pCol, char fName[30])
{
    int i =0;
    int j =0;
    int row, col, amount, rLoc, cLoc, code;
    int **mapArr;
    FILE* fp = fopen(fName, "r");

    if(fp==NULL)
    {
        printf("File cannot be opened \n");

    }
    else
    {
        fscanf(fp, "%d %d %d", &amount, &row, &col);
    

        mapArr = (int**) malloc(row * sizeof(int)*10);      /* Creating */
        for(i = 0; i < row; i++)                            /*  the new */
        {
            mapArr[i] = malloc(col * sizeof(int)*10);       /* 2D array */
        }

        for(i = 0; i < row; i++)
        {
            for ( j = 0; j < col; j++)
            {
                mapArr[i][j] = 5; /*Code for Empty spaces */
            }
        }

        while(!feof(fp))
        {
            fscanf(fp, "%d %d %d", &rLoc, &cLoc, &code);

            /* Assigning the relavent values to the array */
            if (code == 0)
            {
                mapArr[rLoc][cLoc] = 0;
            }

            if (code == 1)
            {
                mapArr[rLoc][cLoc] = 1;
            }

            if (code == 2)
            {
                mapArr[rLoc][cLoc] = 2;
            }

            if (code == 3)
            {
                mapArr[rLoc][cLoc] = 3;
            }
        }
        fclose(fp);

        mapArr[0][0] = 4;  /* This is for the #s in the border of the map*/
        mapArr[0][col-1] = 4;
        mapArr[row- 1][0] = 4;
        mapArr[row-1][col-1] = 4;

        for ( i = 1; i < (row-1); i++)
        {
            mapArr[i][0] = 8;      /*This is for the |s in the border of the map */ 
            mapArr[i][(col-1)] = 8;
        }
    
        for(j = 1; j < (col-1); ++j) /* This is for the - in the border of the map */
        {
            mapArr[0][j] = 6;
            mapArr[(row -1)][j] = 6;
        }
    }
    *pArray = mapArr;       /* Pointing the pointer to the array */
    *pRow = row;            /* Pointing the row */
    *pCol = col;            /* Pointing the columns */

}
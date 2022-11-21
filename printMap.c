#include <stdio.h>
#include <stdlib.h>

void printMap(int **mapArray, int *pRow, int *pCol, char playerSymb)
{

    int i =0;
    int j = 0;
    
    int  row = *pRow;
    int  col = *pCol;
 
    system("clear");
    for(i = 0; i < (row); ++i)
    {
        for(j = 0; j < (col); ++j)
        {
            if (mapArray[i][j] == 0)
            { 
                printf("%c", playerSymb);
            }
            if (mapArray[i][j] == 1)
            { 
                printf("%c", '~');
            }
            if (mapArray[i][j] == 2)
            { 
                printf("%c", 'x');      
            }
            if (mapArray[i][j] == 3)
            { 
                printf("%c", 'O');      
            }
            if (mapArray[i][j] == 5)
            { 
                printf("%c", ' ');      
            }
            if (mapArray[i][j] == 4)
            { 
                printf("%c", '#');      
            }
            if (mapArray[i][j] == 6)
            { 
                printf("%c", '-');      
            }
            if (mapArray[i][j] == 8)
            { 
                printf("%c", '|');      
            } 
        }
        printf("\n");
    }
    
}
#include<stdlib.h>
#include<stdio.h>
#include"control.h"
#include "linkedList.h"

void control(int **mapArray, int *pRow, int *pCol)
{

    int i =0;
    int j =0;
    void *inTemp;
    char outTemp;
    int playerRow, playerCol, goalRow, goalCol, snakeRow, snakeCol;
    char userIn; 
    char playerSymb;
    int  row = *pRow;
    int  col = *pCol;

    LinkedListNode* lastVal; 
    LinkedList* list;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;

    playerSymb = '^';
    printMap(mapArray, pRow, pCol, playerSymb);

    for(i = 0; i < (row); ++i)
    {
        for(j = 0; j < (col); ++j)
        {
            if (mapArray[i][j] == 0)       /* Geting the player location */
            {
                playerRow = i;
                playerCol = j;
            }
            if (mapArray[i][j] == 2)       /*Getting the goal location */
            {
                goalRow = i;
                goalCol = j;
            }
            if (mapArray[i][j] == 1)
            {
                snakeRow = i;
                snakeCol = j;
            }  
        }
    }

    while ((mapArray[goalRow][goalCol] == 2) && (mapArray[snakeRow][snakeCol] == 1) && (mapArray[playerRow][playerCol] == 0) )
    {
        disableBuffer();
        scanf("%c", &userIn);
        if (userIn != 'u')
        {
            inTemp = &userIn;
        }

        /*printf("%c",*((char *)inTemp));*/
        insertFirst(list,inTemp);
        if(userIn == 's')
        {
            insertFirst(list,inTemp);
            if (playerRow >= snakeRow)
            {
                if(((mapArray[snakeRow + 1][snakeCol]) != 2) && ((mapArray[snakeRow + 1][snakeCol]) != 3)) 
                {
                    mapArray[snakeRow][snakeCol] = 5;
                    mapArray[snakeRow + 1][snakeCol]= 1;
                    snakeRow = snakeRow + 1;
                }
            }
            if (playerRow <= snakeRow)
            {
                if(((mapArray[snakeRow - 1][snakeCol]) != 2) && ((mapArray[snakeRow - 1][snakeCol]) != 3)) 
                {
                    mapArray[snakeRow][snakeCol] = 5;
                    mapArray[snakeRow - 1][snakeCol]= 1;
                    snakeRow = snakeRow - 1;
                }
            }

            if ((mapArray[playerRow + 1][playerCol]) == 5 || ((mapArray[playerRow + 1][playerCol]) == 2) || ((mapArray[playerRow + 1][playerCol]) == 1)) 
            {
                mapArray[playerRow][playerCol]= 5;     /* Manipulating the array acording to the controls */
                mapArray[playerRow + 1][playerCol]= 0;
                playerRow = playerRow + 1;
                playerSymb = 'v';
                printMap(mapArray, pRow, pCol, playerSymb);   /* reprinting the map */
            }
        }
 
        if(userIn == 'w')
        {
            insertFirst(list,inTemp);
            if (playerRow >= snakeRow)
            {
                if(((mapArray[snakeRow + 1][snakeCol]) != 2) && ((mapArray[snakeRow + 1][snakeCol]) != 3))  
                {
                    mapArray[snakeRow][snakeCol] = 5;
                    mapArray[snakeRow + 1][snakeCol]= 1;
                    snakeRow = snakeRow + 1;
                }
            }
            if (playerRow <= snakeRow)
            {
                if(((mapArray[snakeRow - 1][snakeCol]) != 2) && ((mapArray[snakeRow - 1][snakeCol]) != 3))
                {
                    mapArray[snakeRow][snakeCol] = 5;
                    mapArray[snakeRow - 1][snakeCol]= 1;
                    snakeRow = snakeRow - 1;
                }
            }

            if ((mapArray[playerRow -1 ][playerCol]) == 5 || ((mapArray[playerRow -1 ][playerCol]) == 2) || ((mapArray[playerRow -1 ][playerCol]) == 1))
            {
                mapArray[playerRow][playerCol]= 5;          
                mapArray[playerRow - 1][playerCol]= 0;         /* Manipulating the array acording to the controls */
                playerRow = playerRow - 1;
                playerSymb = '^';
                printMap(mapArray, pRow, pCol, playerSymb);   /* reprinting the map */
            }
        }

        if(userIn == 'a')
        {
            insertFirst(list,inTemp);
            if (playerCol >= snakeCol)
            {
                if(((mapArray[snakeRow][snakeCol + 1]) != 2) && ((mapArray[snakeRow][snakeCol + 1]) != 3))
                {
                    mapArray[snakeRow][snakeCol] = 5;
                    mapArray[snakeRow][snakeCol + 1]= 1;
                    snakeCol = snakeCol + 1;
                }
            }
            if (playerCol <= snakeCol)
            {
                if(((mapArray[snakeRow][snakeCol - 1]) != 2) && ((mapArray[snakeRow][snakeCol - 1]) != 3))
                {
                    mapArray[snakeRow][snakeCol] = 5;
                    mapArray[snakeRow][snakeCol -1]= 1;
                    snakeCol = snakeCol - 1;
                }
            }

            if ((mapArray[playerRow][playerCol - 1]) == 5 || ((mapArray[playerRow][playerCol - 1]) == 2) || ((mapArray[playerRow][playerCol - 1]) == 1))
            {
                mapArray[playerRow][playerCol]= 5;
                mapArray[playerRow][playerCol -1]= 0;          /* Manipulating the array acording to the controls */
                playerCol = playerCol - 1;
                playerSymb = '<';
                printMap(mapArray, pRow, pCol, playerSymb);    /* reprinting the map */
            }
        }

        if(userIn == 'd')
        {
            insertFirst(list,inTemp);
            if (playerCol >= snakeCol)
            {
                if(((mapArray[snakeRow][snakeCol + 1]) != 2) && ((mapArray[snakeRow][snakeCol + 1]) != 3))
                {
                    mapArray[snakeRow][snakeCol] = 5;
                    mapArray[snakeRow][snakeCol + 1]= 1;
                    snakeCol = snakeCol + 1;
                }
            }
            if (playerCol <= snakeCol)
            {
                if(((mapArray[snakeRow][snakeCol - 1]) != 2) && ((mapArray[snakeRow][snakeCol - 1]) != 3))
                {
                    mapArray[snakeRow][snakeCol] = 5;
                    mapArray[snakeRow][snakeCol -1]= 1;
                    snakeCol = snakeCol - 1;
                }
            }

            if ((mapArray[playerRow][playerCol + 1]) == 5 || ((mapArray[playerRow][playerCol + 1]) == 2) || ((mapArray[playerRow][playerCol + 1]) == 1))
            {
                mapArray[playerRow][playerCol]= 5;
                mapArray[playerRow][playerCol + 1]= 0;          /* Manipulating the array acording to the controls */
                playerCol = playerCol + 1;
                playerSymb = '>';
                printMap(mapArray, pRow, pCol, playerSymb);    /* reprinting the map */
            }
        }
        if(userIn == 'u')
        {
            lastVal = removeFirst(list);
            outTemp = *((char *)lastVal->data);
            /*outTemp = removeFirst(list);*/
            /*printf("%c", lastVal);*/
            /*printf("%c", outTemp);*/
            /*printf("%c", removeFirst(list));
            printf("%c", removeFirst(list));
            printf("%c", removeFirst(list));
            printf("%c", removeFirst(list));*/

            if(outTemp == 'w')
            {
                if (playerRow >= snakeRow)
                {
                    if(((mapArray[snakeRow + 1][snakeCol]) != 2) && ((mapArray[snakeRow + 1][snakeCol]) != 3)) 
                    {
                        mapArray[snakeRow][snakeCol] = 5;
                        mapArray[snakeRow + 1][snakeCol]= 1;
                        snakeRow = snakeRow + 1;
                    }
                }   
                if (playerRow <= snakeRow)
                {
                    if(((mapArray[snakeRow - 1][snakeCol]) != 2) && ((mapArray[snakeRow - 1][snakeCol]) != 3)) 
                    {
                        mapArray[snakeRow][snakeCol] = 5;
                        mapArray[snakeRow - 1][snakeCol]= 1;
                        snakeRow = snakeRow - 1;
                    }
                }

                if ((mapArray[playerRow + 1][playerCol]) == 5 || ((mapArray[playerRow + 1][playerCol]) == 2) || ((mapArray[playerRow + 1][playerCol]) == 1)) 
                {
                    mapArray[playerRow][playerCol]= 5;     /* Manipulating the array acording to the controls */
                    mapArray[playerRow + 1][playerCol]= 0;
                    playerRow = playerRow + 1;
                    playerSymb = 'v';
                    printMap(mapArray, pRow, pCol, playerSymb);   /* reprinting the map */
                }
            }

            if(outTemp == 's')
            {
                if (playerRow >= snakeRow)
                {
                    if(((mapArray[snakeRow + 1][snakeCol]) != 2) && ((mapArray[snakeRow + 1][snakeCol]) != 3))  
                    {
                        mapArray[snakeRow][snakeCol] = 5;
                        mapArray[snakeRow + 1][snakeCol]= 1;
                        snakeRow = snakeRow + 1;
                    }
                }
                if (playerRow <= snakeRow)
                {
                    if(((mapArray[snakeRow - 1][snakeCol]) != 2) && ((mapArray[snakeRow - 1][snakeCol]) != 3))
                    {
                        mapArray[snakeRow][snakeCol] = 5;
                        mapArray[snakeRow - 1][snakeCol]= 1;
                        snakeRow = snakeRow - 1;
                    }
                }

                if ((mapArray[playerRow -1 ][playerCol]) == 5 || ((mapArray[playerRow -1 ][playerCol]) == 2) || ((mapArray[playerRow -1 ][playerCol]) == 1))
                {
                    mapArray[playerRow][playerCol]= 5;          
                    mapArray[playerRow - 1][playerCol]= 0;         /* Manipulating the array acording to the controls */
                    playerRow = playerRow - 1;
                    playerSymb = '^';
                    printMap(mapArray, pRow, pCol, playerSymb);   /* reprinting the map */
                }
            }

            if(outTemp == 'a')
            {
                if (playerCol >= snakeCol)
                {
                    if(((mapArray[snakeRow][snakeCol + 1]) != 2) && ((mapArray[snakeRow][snakeCol + 1]) != 3))
                    {
                        mapArray[snakeRow][snakeCol] = 5;
                        mapArray[snakeRow][snakeCol + 1]= 1;
                        snakeCol = snakeCol + 1;
                    }
                }
                if (playerCol <= snakeCol)
                {
                    if(((mapArray[snakeRow][snakeCol - 1]) != 2) && ((mapArray[snakeRow][snakeCol - 1]) != 3))
                    {
                        mapArray[snakeRow][snakeCol] = 5;
                        mapArray[snakeRow][snakeCol -1]= 1;
                        snakeCol = snakeCol - 1;
                    }
                }

                if ((mapArray[playerRow][playerCol + 1]) == 5 || ((mapArray[playerRow][playerCol + 1]) == 2) || ((mapArray[playerRow][playerCol + 1]) == 1))
                {
                    mapArray[playerRow][playerCol]= 5;
                    mapArray[playerRow][playerCol + 1]= 0;          /* Manipulating the array acording to the controls */
                    playerCol = playerCol + 1;
                    playerSymb = '>';
                    printMap(mapArray, pRow, pCol, playerSymb);    /* reprinting the map */
                }
            }

            if(outTemp == 'd')
            {
                if (playerCol >= snakeCol)
                {
                    if(((mapArray[snakeRow][snakeCol + 1]) != 2) && ((mapArray[snakeRow][snakeCol + 1]) != 3))
                    {
                        mapArray[snakeRow][snakeCol] = 5;
                        mapArray[snakeRow][snakeCol + 1]= 1;
                        snakeCol = snakeCol + 1;
                    }
                }
                if (playerCol <= snakeCol)
                {
                    if(((mapArray[snakeRow][snakeCol - 1]) != 2) && ((mapArray[snakeRow][snakeCol - 1]) != 3))
                    {
                        mapArray[snakeRow][snakeCol] = 5;
                        mapArray[snakeRow][snakeCol -1]= 1;
                        snakeCol = snakeCol - 1;
                    }
                }

                if ((mapArray[playerRow][playerCol - 1]) == 5 || ((mapArray[playerRow][playerCol - 1]) == 2) || ((mapArray[playerRow][playerCol - 1]) == 1))
                {
                    mapArray[playerRow][playerCol]= 5;
                    mapArray[playerRow][playerCol -1]= 0;          /* Manipulating the array acording to the controls */
                    playerCol = playerCol - 1;
                    playerSymb = '<';
                    printMap(mapArray, pRow, pCol, playerSymb);    /* reprinting the map */
                }
            }  
        }
    }
    
    if (mapArray[goalRow][goalCol] == 0)                       /*Checking whether the player has reached the goal location */
    {
        printf("You win!! \n");
    }

    if (mapArray[snakeRow][snakeCol] == 0)                       /*Checking whether the player has reached the goal location */
    {
        printf("You lose!! \n");
    }

    if (mapArray[playerRow][playerCol] == 1)                       /*Checking whether the player has reached the goal location */
    {
        printf("You lose!! \n");
    }

    enableBuffer(); 
}
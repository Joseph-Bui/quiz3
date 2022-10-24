#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <stdbool.h>

const int SIZE = 3; 
int grid1[SIZE][SIZE] = {{0,0,0}, {0,0,0}, {0,0,0}};
int grid2[9] = {1,2,3,4,5,6,7,8,9};

//create a function that adds up all the columns and rows of the Lo Shu board
bool isMagicSquare(int array[SIZE][SIZE])
{
    bool isMagic = true;
    
    //going through rows to cheeck if they add up to 15
    for (int i = 0; i < SIZE; i++)
    {
        int row = 0;
        for (int j = 0; j < SIZE; j++)
        {
            row += array[i][j];
        }
        if(row != 15)
        {
            isMagic = false;
        }
    }

    //going through columns to check if they add up to 15
    for (int j = 0; j < SIZE; j++)
    {
        int column = 0;
        for (int i = 0; i < SIZE; i++)
        {
            column += array[i][j];
        }
        if(column != 15)
        {
            isMagic = false;
        }
    }

    //checking if diagonals add up to 15
    int diagonal1 = array[0][0] + array[1][1] + array[2][2];
    int diagonal2 = array[2][0] + array[1][1] + array[0][2];

    if(diagonal1 != 15)
    {
        isMagic = false;
    }

    if(diagonal2 != 15)
    {
        isMagic = false;
    }

    return isMagic;
}

//create a functoin that prints out the board
void printBoard(int array[SIZE][SIZE])
{
    printf("\n");

    //go through the array and print out each element
    for(int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if(j == 0)
            {
                printf("[");
            }
            printf("%d", array[i][j]);
        }
        printf("]\n");
    }
}

//shuffle the board and put random numbers in each square
void boardShuffle()
{
    //go through the array and switch numbers
    for (int i = 8; i > 0; i--)
    {
        int position = (rand() % (i + 1));
        int temp = grid2[i];
        grid2[i] = grid2[position];
        grid2[position] = temp;
    }
}

//function that stores the shuffled board into a new array
void createBoard()
{
    boardShuffle();
    int position = 0;

    //go through grid 2 and store each number in grid 1.
    for(int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            grid1[i][j] = grid2[position];
            position++;
        }
    }
}

int main()
{
    // create a random number generator and new game board
    srand(time(0));
    
    //create a loop that creates Lo Shu game boards until the magic square is found
    int randomBoard[SIZE][SIZE] = {4,3,8,9,5,1,2,7,6};

    bool found = false;
    int count = 0;

    //checking a randomly generated loshu 
    while(!found)
    {
        createBoard();
        printBoard(grid1);
        count++;
        if(isMagicSquare(grid1))
        {
            found = true;
        }
    }
    
    printf("\nMagic square has been found. Total attempts: %d\n", count);

    int isLoShu[SIZE][SIZE] = {4,9,2,3,5,7,8,1,6};
    int notLoShu[SIZE][SIZE] = {4,9,2,5,7,3,8,6,1};

    //testing an array that is a loshu
    if(isMagicSquare(isLoShu))
    {
        printBoard(isLoShu);
        printf("\nThis board is a magic square\n");
    }

    //tesing an array that is not a loshu
    if(!isMagicSquare(notLoShu))
    {
        printBoard(notLoShu);
        printf("\nThis is not a magic square\n");
    }
}
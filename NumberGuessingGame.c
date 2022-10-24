#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //declare local variables
    int min = 1;
    //store the user input into a file and store that number in the max
    int max = 10;
    int playerChoice;
    char guess;

    //create a number randomizer
    srand(time(0));
    int answer = (rand() % max) + min;

    //print out the board and play the game until the player chooses 3
    do{

        printf("\nPress 1 to play the game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n");
        printf("Select an option: ");
        scanf("%d", &playerChoice);

        if(playerChoice == 1)
        {
            do{
                printf("Enter a number: ");
                scanf("%s", &guess);
                
                if(guess == 'q')
                {
                    break;
                }
                else if(atoi(&guess) > answer)
                {
                    printf("Guess is too high.\n");
                }

                else if(atoi(&guess) < answer)
                {
                    printf("Guess is too low.\n");
                }

                else if(atoi(&guess) == answer)
                {
                    printf("You have guessed the correct number\n");
                }
                

            }while(atoi(&guess) != answer);
        }
            
        if(playerChoice == 2)
        {
            printf("Enter a new max: ");
            scanf("%d", &max);
            answer = (rand() % max) + min;
        }
    
    }while(playerChoice != 3);
    
    return 0;
}
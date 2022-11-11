/***************************************************************
 *Class:                     CSCI 112                                                                                        *
 *Instructor:               Ronald Burgher                                                                              *
 *Programmer:          Ethan Grant                                                                                    *
 *Project:                  Fore  Project                                                                                   *
 *************************************************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Declare prototype
void getScore(int theScores[], int *totals);

int main(void)
{
    // Declare Variables
    int scores[9] = {0};
    int par[] = {4,5,4,5,4,3,4,3,4};
    int total;
    int pars = 0;
    int birdies = 0;
    int bogeys = 0;
    
    // Get user input
    getScore(scores, &total);
    
    printf("   --------- Golf Score Calculator ---------   \n");

    // Figure out if score on hole was a par, birdie, or bogey
    for (int i = 0; i < 9; i++)
    {
        printf("The score on hole # %d was: %d   Par is: %d -", i+1, scores[i], par[i]);
        if (par[i] > scores[i])
        {
            printf(" Birdie!\n");
            ++ birdies;
        }
        if (par[i] < scores[i]) {
            printf(" Bogey!\n");
            ++ bogeys;
        }
        if (par[i] == scores[i]) {
            printf(" Par\n");
            ++ pars;
        }
    }
    
    // Declare par amount and score amount
    printf("\nPar is: 36 - total score was: %d\n", total);
    
    // Declare the total number of pars, birdies, and bogeys
    printf("\nNumber of Pars: %d", pars);
    // Birdie = Under Par
    printf("\nNumber of Birdies: %d", birdies);
    // Bogey = Above Par
    printf("\nNumber of Bogeys: %d\n", bogeys);
    
return 0;
}

// Get user input
void getScore(int theScores[], int *totals)
{
    for (int hole = 0; hole < 9; hole++)
    {
        printf("Enter score on hole number #%d: ", hole+1);
        while (scanf("%d", &theScores[hole]) != 1)
        {
            while (getchar() != '\n');
            printf("Incorrect Input\nEnter score on hole number #%d: ", hole+1);
        }
        *totals += theScores[hole];
    }
}

 


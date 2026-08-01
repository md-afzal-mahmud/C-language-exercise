/* Code for a basic cricket game where you can type a number between
   1 and 6 and play against the computer */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
    int yourvalue, computervalue;
    int yourscore = 0, computerscore = 0;
    int yourwicket = 2, computerwicket = 2;
    int toss, flipToss;
    int max = 6, min = 1;

    srand(time(NULL));

    // Toss logic: 1 = Heads, 2 = Tails
    printf("Call the toss! Enter 1 for Heads or 2 for Tails: ");
    scanf("%d", &toss);

    flipToss = (rand() % 2) + 1;  // generates 1 or 2

    if (toss == 1 || toss == 2) {
        if (toss == flipToss) {
            printf("You won the toss! You will bat first.\n");
            Sleep(1000);

            // Batting
            while (yourwicket > 0) {
                printf("Enter a run (1-6): ");
                scanf("%d", &yourvalue);
                computervalue = (rand() % (max - min + 1)) + min;

                if (yourvalue == computervalue) {
                    printf("You are OUT! Computer guessed %d.\n", computervalue);
                    yourwicket--;
                } else {
                    yourscore += yourvalue;
                    printf("You scored %d. Total = %d\n", yourvalue, yourscore);
                }
                Sleep(1000);
            }

            printf("Your innings finished. Final score = %d\n", yourscore);
            Sleep(1000);

            // Bowling
            while (computerwicket > 0 && computerscore <= yourscore) {
                printf("Enter your bowling number (1-6): ");
                scanf("%d", &yourvalue);
                computervalue = (rand() % (max - min + 1)) + min;

                if (yourvalue == computervalue) {
                    printf("Computer is OUT! You guessed %d.\n", yourvalue);
                    computerwicket--;
                } else {
                    computerscore += computervalue;
                    printf("Computer scored %d. Total = %d\n", computervalue, computerscore);
                }
                Sleep(1000);
            }

        } else {
            printf("You lost the toss! Computer bats first.\n");
            Sleep(1000);

            // Computer batting
            while (computerwicket > 0) {
                printf("Enter your bowling number (1-6): ");
                scanf("%d", &yourvalue);
                computervalue = (rand() % (max - min + 1)) + min;

                if (yourvalue == computervalue) {
                    printf("Computer is OUT! You guessed %d.\n", yourvalue);
                    computerwicket--;
                } else {
                    computerscore += computervalue;
                    printf("Computer scored %d. Total = %d\n", computervalue, computerscore);
                }
                Sleep(1000);
            }

            printf("Computer innings finished. Final score = %d\n", computerscore);
            Sleep(1000);

            // Your batting
            while (yourwicket > 0 && yourscore <= computerscore) {
                printf("Enter a run (1-6): ");
                scanf("%d", &yourvalue);
                computervalue = (rand() % (max - min + 1)) + min;

                if (yourvalue == computervalue) {
                    printf("You are OUT! Computer guessed %d.\n", computervalue);
                    yourwicket--;
                } else {
                    yourscore += yourvalue;
                    printf("You scored %d. Total = %d\n", yourvalue, yourscore);
                }
                Sleep(1000);
            }
        }

        // Final result
        printf("\nFinal Scores:\nYou = %d runs, Computer = %d runs\n", yourscore, computerscore);
        if (yourscore > computerscore) {
            printf(" You won the match!\n");
        } else if (yourscore < computerscore) {
            printf(" Computer won the match!\n");
        } else {
            printf(" Match tied!\n");
        }

    } else {
        printf("Invalid toss choice! Please enter 1 or 2.\n");
    }

    return 0;
}



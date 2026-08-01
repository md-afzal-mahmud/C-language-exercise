#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int round;
    int yourShoot, yourSave;
    int computerShoot, computerSave;
    int yourScore = 0, computerScore = 0;
    int toss, computerChoice;
    int max = 2, min = 1;

    srand(time(NULL));

    // Toss
    printf("Choose toss: Head(1) or Tail(2): ");
    scanf("%d", &toss);
    computerChoice = rand() % (max - min + 1) + min;

    int youShootFirst;
    if (toss == computerChoice) {
        printf("You won the toss! You will shoot first.\n");
        youShootFirst = 1;
    } else {
        printf("Computer won the toss! Computer will shoot first.\n");
        youShootFirst = 0;
    }

    // 5 rounds each
    for (round = 1; round <= 5; round++) {
        printf("\n--- Round %d ---\n", round);

        if (youShootFirst) {
            // Your shot
            printf("Your shot (1=Right, 2=Left): ");
            scanf("%d", &yourShoot);
            while (yourShoot != 1 && yourShoot != 2) {
                printf("Invalid input. Enter 1 or 2: ");
                scanf("%d", &yourShoot);
            }

            computerSave = rand() % (max - min + 1) + min;
            if (yourShoot == computerSave) {
                printf("Saved by computer.\n");
            } else {
                printf("Goal!\n");
                yourScore++;
            }

            // Computer shot
            printf("Computer shoots. Your save (1=Right, 2=Left): ");
            scanf("%d", &yourSave);
            while (yourSave != 1 && yourSave != 2) {
                printf("Invalid input. Enter 1 or 2: ");
                scanf("%d", &yourSave);
            }

            computerShoot = rand() % (max - min + 1) + min;
            if (yourSave == computerShoot) {
                printf("You saved it!\n");
            } else {
                printf("Goal by computer.\n");
                computerScore++;
            }
        } else {
            // Computer shot first
            printf("Computer shoots. Your save (1=Right, 2=Left): ");
            scanf("%d", &yourSave);
            while (yourSave != 1 && yourSave != 2) {
                printf("Invalid input. Enter 1 or 2: ");
                scanf("%d", &yourSave);
            }

            computerShoot = rand() % (max - min + 1) + min;
            if (yourSave == computerShoot) {
                printf("You saved it!\n");
            } else {
                printf("Goal by computer.\n");
                computerScore++;
            }

            // Your shot
            printf("Your shot (1=Right, 2=Left): ");
            scanf("%d", &yourShoot);
            while (yourShoot != 1 && yourShoot != 2) {
                printf("Invalid input. Enter 1 or 2: ");
                scanf("%d", &yourShoot);
            }

            computerSave = rand() % (max - min + 1) + min;
            if (yourShoot == computerSave) {
                printf("Saved by computer.\n");
            } else {
                printf("Goal!\n");
                yourScore++;
            }
        }

        printf("Score after Round %d → You: %d | Computer: %d\n", round, yourScore, computerScore);
    }

    // Final result
    printf("\nFinal Score → You: %d | Computer: %d\n", yourScore, computerScore);
    if (yourScore > computerScore) {
        printf("You win!\n");
    } else if (yourScore < computerScore) {
        printf("Computer wins!\n");
    } else {
        printf("It’s a draw!\n");
    }

    return 0;
}

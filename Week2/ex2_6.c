#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int d6();

int d10();

int main() {
    int choice = 0;
    while (choice != 3) {
        printf("Select an option: \n1) Roll a D6. \n2) Roll a D10. \n3) Quit.\n");
        int valid = scanf("%d", &choice);
        if (valid != 1) { // validating input
            printf("Invalid input. \n");
            while (getchar() != '\n') {
            } choice = 4;
        }
        if (choice == 1) { // Executing responses to choices made by the user
            d6();
        } else if (choice == 2) {
            d10();
        } else if (choice == 3) {
            printf("Good bye.");
        } else if (choice > 3) {
            printf("Please enter a valid choice.\n");
        }
    }
    return 0;
}

int d6() {
    srand(time(NULL)); // Using time as a unique seed for rolling a random number
    int d6roll = (rand() % 6) + 1;
    printf("You rolled a %d! \n", d6roll);
    return 0;
}

int d10() {
    int d10roll = (rand() % 10) + 1; // Using time as a unique seed for rolling a random number
    printf("You rolled a %d! \n", d10roll);
    return 0;
}

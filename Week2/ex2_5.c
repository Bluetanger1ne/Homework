#include <stdio.h>
#define LOW 1
#define HIGH 6

int read_range(int low, int high);


int main() {
    for (int i = 0; i < 3; i++) {
        int roll = read_range(LOW,HIGH);
        if (roll < 6) {
            printf("I got %d. I win! \n", roll + 1);
        } else {
            printf("I got %d. It's a tie!\n",HIGH);
        }
    }
    printf("\nBetter luck next time. Bye!");
}


int read_range(int low, int high) {
    int number = 0;
    int valid = 0;
    while (valid != 1) {
        printf("Please enter a number between %d and %d: \n", low, high);
        int result = scanf("%d", &number);
        if (result != 1) {
            printf("Invalid input\n");
            valid = 0;
            while (getchar() != '\n') {
            }
        }
        else if (number < low || number > high) {
            printf("Please enter a number within the given range.\n");
            valid = 0;
        } else {
            valid = 1;
        }
    }
    return number;
}


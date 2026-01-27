#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value);


int main() {
    int number = 0;
    int running = 1;
    while (running < 4) { // Loop until the user enters an invalid input three times.
        printf("How much money do I have?\n");
        bool check = read_positive(&number);
        if (check == true) {
            printf("You did not get it right. I have %d euros.\n\n", (number * 2) + 20);
        } else {
            running +=1;
        }
    } // Once the user has entered an invalid input three times, the program stops
    printf("\nI give up! See you later!\n");
    return 0;
}


bool read_positive(int *value) {
    int positive_num = 0;
    printf("Enter a positive number:");
    int scan = scanf("%d", &positive_num);
    if (positive_num < 0) { // error validation
        printf("Invalid number!\n");
        return false;
    }
    if (scan != 1) { // error validation
        printf("Invalid input!\n");
        while (getchar() != '\n') {
        }
        return false;
    } // Only true return, where the entered number is above 0. ( Not sure if 0 should be counted as a positive number..
    if (positive_num >= 0) {
        *value = positive_num;
        return true;
    }
}

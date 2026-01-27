#include <stdio.h>

int read_integer(void);

int main () {
    int running = 1;
    int total = 0;
    int amount = 0;
    while (running != 0) {
        int current = read_integer();
        if (current >= 0) {
            total += current;
            amount ++;
        }
        if (current < 0) {
            running = 0;
        }
        else {
            running = 1;
        }
    }
    printf("\nYou entered %d positive numbers. The average is %.3f",amount,(float)total/(float)amount);
}


int read_integer() {
    int ispositive = 1;
    int number;
    while (ispositive != 0) {
        printf("Please enter a positive number or a negative one to stop: ");
        int result = scanf("%d",&number);
        if (result == 1) {
            ispositive = 0;
        }
        else {
            while (getchar() != '\n');
            printf("invalid input\n");

            ispositive = 1;
        }
    }
    return number;
}

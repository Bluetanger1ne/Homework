#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int find_first(const unsigned int *array, unsigned int what);

int main() {
    srand(time(NULL)); // Using time as a unique seed for rolling a random number
    unsigned int array[20];
    array[19] = 0;
    for (int i = 0; i < 19; i++) { // Fill the array with random integers between 1-20.
        int random = rand() % 20 + 1;
        array[i] = random;
    }
    for (int i = 0; i < 20; i++) {
        printf("%u \n", array[i]);
    }
    unsigned int input = 1;
    while (input != 0) {
        printf("Please enter a number to search for or 0 to stop:"); // Ask for user input
        scanf("%d", &input);
        int result = find_first(array, input);
        if (result == -1 && input != 0) { // Verify results, based on whats returned from find_first.
            printf("Number not found.\n");
        } else if (input != 0) {
            printf("The number is at index [%d].\n", result);
        }
    }
}


int find_first(const unsigned int *array, unsigned int what) {
    int index = -1;
    int i= 0;
    while (array[i] != 0) { // Check through the array, without knowing the size. Stop when 0 is reached.
        if (array[i] == what) {
            return i;
        }
        i++;
    }
    return index;
}



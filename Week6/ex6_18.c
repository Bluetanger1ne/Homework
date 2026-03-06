#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX_SIZE 30

int generate_random();
void clear_input_buffer();

int main() {
    srand(time(NULL)); // Use time as a seed for the random number
    char value;
    int number = 0;
    bool running = true;
    while (running != false) {
        printf("Please enter a number between 0-15, or a negative number to stop:\n"); // Ask for input
        fgets(&value,MAX_SIZE,stdin);
        if (sscanf(&value,"%d",&number) == 1) { // Validate that the input is a number
            if (number<=15 && number >= 0) { // Validate that the input is within range, and generate the random number and print it in hexadecimal.
                int rnumber = generate_random();
                printf("Generated hexadecimal: %x\n",rnumber);
                int shift = rnumber >> number; // Shift the number by the number of bits given by the user
                int res = shift & 0x3F; // clear all except bits 0-5
                printf("Shifted hexadecimal by %d: %x\n",number,shift);
                printf("Final result: %02x\n\n",res); // Print the final result with 2 hex digits, and possible leading zeroes

            } else if (number>15){ // Check if number is above the range
                printf("Invalid number\n");
                clear_input_buffer();
            } else { // Check if number is negative
                running = false;
            }
        }
        else {
            printf("Enter a real number please..\n");
        }


    }
    return 0;
}

int generate_random() {
    int number = rand(); // Generate the random number
    return number;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
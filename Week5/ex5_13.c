#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 80

int main() {
    char filename[MAX_SIZE];
    FILE *my_file;
    int row = 0;
    int value;
    int lowest;
    int highest;
    int first_number = 1;

    printf("Please enter the name of a file you wish to open, with \".txt\" included.\n");
    fgets(filename,MAX_SIZE,stdin);
    if (filename[strlen(filename) - 1] == '\n') {
        // Removing the new line
        filename[strlen(filename) - 1] = '\0'; // Replacing it with \0
    }
    my_file = fopen(filename, "r");
    if (my_file == NULL) { // Checking if the file can be opened or if it exists and displaying an error message
        char error[MAX_SIZE] = "File not found: ";
        fprintf(stderr, "%s%s\n",error,filename);
    }
    else {
        //printf("File found!\n");
        //printf("It contains the following:\n");
        while(!feof(my_file)) { // Open the file and scan the numbers in it.
            if(fgets(filename, MAX_SIZE, my_file) != NULL) {
                if (sscanf(filename, "%d", &value) == 1) {
                    if (first_number == 1) { // Set the first found value as both the highest and the lowest number
                        lowest = value;
                        highest = value;
                        first_number = 0;
                    }
                    if (value <= lowest) { // Compare every consecutive number to the highest and lowest numbers, and adjust accordingly
                        lowest = value;
                    } else if (value >= highest) {
                        highest = value;
                    }
                    row++; // Keep track of how many numbers were found
                    //printf("%d\n", value);
                }
            }
        } // Print out the results: Highest, lowest and the amount of nmbers read.
        printf("Amount of numbers read: %d\n",row);
        printf("Lowest number: %d\n",lowest);
        printf("Highest number: %d\n",highest);
        fclose(my_file);
    }


    return 0;
}





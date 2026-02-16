#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE_SIZE 80
#define MAX_AMT_LINES 100

int main() {
    char filename[MAX_LINE_SIZE];
    FILE *my_file;
    char contents[MAX_AMT_LINES][MAX_LINE_SIZE];
    int row = 0;

    printf("Please enter the name of a file you wish to open, with \".txt\" included.\n");
    fgets(filename, MAX_LINE_SIZE, stdin);
    if (filename[strlen(filename) - 1] == '\n') {
        filename[strlen(filename) - 1] = '\0';
    }

    my_file = fopen(filename, "r");

    if (my_file == NULL) {
        // Checking if the file can be opened or if it exists and displaying an error message
        char error[MAX_LINE_SIZE] = "File not found: ";
        fprintf(stderr, "%s%s\n", error, filename);
    } else {
        //printf("File found!\n");
        //printf("It contains the following:\n");
        while (row < MAX_AMT_LINES && !feof(my_file)) {
            // Open the file and read lines from it.
            if (fgets(contents[row], MAX_LINE_SIZE, my_file) != NULL) {
                row++;
            }
        }
    }

    fclose(my_file);

    // Convert all characters to uppercase.
    for (int i = 0; i < row; i++) {
        for (int j = 0; contents[i][j] != '\0'; j++) {
            contents[i][j] = toupper(contents[i][j]);
        }
    }
    // After reading, and closing the file, open the file in writing mode.
    my_file = fopen(filename, "w");
    // Add all the converted letters to the original file.
    for (int i = 0; i < row; i++) {
        fputs(contents[i], my_file);
    }
    fclose(my_file);

    printf("File processed!\n");

    return 0;
}

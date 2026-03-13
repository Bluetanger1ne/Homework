#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 100
#define MAX_SIZE 80

bool validate_line(const char line[MAX_LINE_SIZE]);

int checksum(const char line[MAX_LINE_SIZE]);

int main() {
    char filename[MAX_SIZE];
    FILE *my_file;
    char contents[MAX_LINE_SIZE];
    int row = 0;

    printf("Please enter the name of a file you wish to open, with \".txt\" included.\n");
    fgets(filename,MAX_SIZE,stdin);
    if (filename[strlen(filename) - 1] == '\n') {
        // Removing the new line
        filename[strlen(filename) - 1] = '\0'; // Replacing it with \0
    }
    my_file = fopen(filename, "r"); // Open file for reading
    if (my_file == NULL) { // Checking if the file can be opened or if it exists and displaying an error message
        char error[MAX_SIZE] = "File not found: ";
        fprintf(stderr, "%s%s\n", error, filename);

    } else {
        while (row < MAX_LINE_SIZE && !feof(my_file)) {
            // Open the file and read lines from it.
            if (fgets(&contents[row], MAX_SIZE, my_file) != NULL) {
                if (validate_line(&contents[row])) {
                    // Validate that the line has both the "*" and "$" symbols
                    int checksum_being_compared = checksum(&contents[row]);
                    // if it's valid, collect the checksum from the line to be compared to the checksum it should respond to
                    int checksum_cmp = 0;
                    int j = 0;
                    for (j = 0; contents[j] != '*'; j++) {
                    }
                    sscanf(&contents[j + 1], "%2X", &checksum_cmp); //save the checksum that is supposed to be equal to the checksum of the string between "$" and "*"
                    if (checksum_being_compared == checksum_cmp) { // If they are equal, print with prefix [OK]
                        printf("[OK] %s", &contents[row]);
                    } else {
                        printf("[FAIL] %s", &contents[row]); // If they are not equal, print with prefix [FAIL]
                    }
                } else {
                    printf("[FAIL] %s", &contents[row]); // If there are rows without "$" and/or "*", print with prefix [FAIL]
                }
            }
            row++;
        }
    }
    fclose(my_file);
    return 0;
}

bool validate_line(const char line[MAX_LINE_SIZE]) {
    // Line validation to check if the line contains both "$" and "*"
    bool validation = false;
    for (int i = 0; i < MAX_LINE_SIZE; i++) {
        if (line[i] == '*') {
            validation = true;
        }
    } if (line[0] == '$' && validation == true) {
        return true;
    }
    return false;
}
int checksum(const char line[MAX_LINE_SIZE]) {
    // Calculate the checksum of the string between "$" and "*"
    int checksum = 0;
    for (int i = 1; i < MAX_LINE_SIZE && line[i] != '*'; i++) {
        checksum ^= line[i];
    }
    return checksum;
}

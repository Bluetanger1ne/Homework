#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_SIZE 40
#define LINE_SIZE 80

typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int main() {
    menu_item item[ARRAY_SIZE];
    // File handling/opening
    char filename[LINE_SIZE];
    FILE *my_file;
    int row = 0;
    printf("Please enter the name of a file you wish to open, with \".txt\" included.\n");

    fgets(filename,LINE_SIZE,stdin);
    if (filename[strlen(filename) - 1] == '\n') {
        filename[strlen(filename) - 1] = '\0';
    }

    my_file = fopen(filename, "r");
    // Error handling
    if (my_file == NULL) {
        char error[LINE_SIZE] = "File not found: ";
        fprintf(stderr, "%s%s\n", error, filename);
    } else {
        // If the file was found, get the price and name of the items and add them to the array.

        while (row < ARRAY_SIZE && !feof(my_file)) {
            if (fgets(item[row].name, LINE_SIZE, my_file) != NULL) {
                // Find the semicolon
                char *res = strchr(item[row].name, ';');
                if (res != NULL) {
                    *res = '\0';
                    char *price_str = res + 1;
                    item[row].price = atof(price_str);
                    row++;
                }
            }
        }

        // Close the file and print out the menu with format specifiers.
        fclose(my_file);
        for (int i = 0; i < row; i++) {
            printf("%8.2f %s\n", item[i].price, item[i].name);
        }
    }
    return (0);
}

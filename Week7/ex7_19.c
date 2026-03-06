#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ARRAY_SIZE 40
#define LINE_SIZE 80
#define MAX_SIZE 20


typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int sort_price(const void *a, const void *b);

int sort_by_name(const void *a, const void *b);

int main() {
    menu_item items[ARRAY_SIZE];
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
            if (fgets(items[row].name, LINE_SIZE, my_file) != NULL) {
                // Find the semicolon
                char *res = strchr(items[row].name, ';');
                if (res != NULL) {
                    *res = '\0';
                    char *price_str = res + 1;
                    items[row].price = atof(price_str);
                    row++;
                }
            }
        }

        // Close the file and print out the menu with format specifiers and chosen sorting type
        char value;
        int number = 0;
        bool running = true;
        while (running != false) {
            printf("Would you like to sort the menu by price or by name?\n1) By price \n2) By name\n"); // Ask for input
            fgets(&value,MAX_SIZE,stdin);
            if (sscanf(&value, "%d", &number) == 1 && number <= 2) {
                if (number == 1) {
                    // if choice was 1, sort by price
                    qsort(items, row, sizeof(menu_item), sort_price);
                    running = false; // exit loop
                } else if (number == 2) {
                    // if choice was 2, sort by name
                    qsort(items, row, sizeof(menu_item), sort_by_name);
                    running = false; // exit loop
                }
            } else {
                printf("Invalid selection\n");
            }
        }
        fclose(my_file);
        for (int i = 0; i < row; i++) {
            printf("%8.2f %s\n", items[i].price, items[i].name);
        }
    }
    return (0);
}

int sort_by_name(const void *a, const void *b) {
    menu_item ca = *(menu_item *) a;
    menu_item cb = *(menu_item *) b;
    return strcmp(ca.name, cb.name);
}

int sort_price(const void *a, const void *b) {
    menu_item ca = *(menu_item *) a;
    menu_item cb = *(menu_item *) b;
    double price_a = ca.price;
    double price_b = cb.price;

    if (price_a < price_b) {
        return -1;
    }
    if (price_a > price_b) {
        return 1;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 64
#define TWO_CHARS 3

int replace_char(char *str, const char *repl);

int main() {
    char str[MAX_LENGTH];
    char substitution[TWO_CHARS];

    printf("Please enter a string that you wish to be modified: ");
    fgets(str,MAX_LENGTH,stdin);
    if (str[strlen(str) - 1] == '\n') {
        // Removing the new line
        str[strlen(str) - 1] = '\0'; // Replacing it with \0
    }
    printf("Please enter two characters: ");
    fgets(substitution,TWO_CHARS,stdin);
    if (str[strlen(str) - 1] == '\n') {
        // Removing the new line
        str[strlen(str) - 1] = '\0'; // Replacing it with \0
    }

    int count = replace_char(str, substitution);
    if (count == 0) {
        // Checking if the string has been modified
        printf("The string was not modified");
    } else if (count > 0) {
        // Printing both the amount of changed characters and the new sentence
        printf("You replaced %d character(s). \n", count);
        printf("Here is the modified string: %s \n", str);
    }
    return 0;
}

int replace_char(char *str, const char *repl) {
    int amount = 0;
    char being_replaced = repl[0];
    char replaced_with = repl[1];

    for (int i = 0; str[i] != '\0'; i++) {
        // Check through the array, without knowing the size. Stop when 0 is reached.
        if (str[i] == being_replaced || str[i] == being_replaced - 32) {
            /*Check if the character at the given index contains
            the letter we wish to replace ( Either capital or lower-case)*/
            str[i] = replaced_with;
            amount++;
        }
    }
    return amount;
}

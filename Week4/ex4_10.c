#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 64

int main() {
    int running = 1;
    char str[MAX_LENGTH];
    while (running != 0) {
        printf("Please enter a string, or 'stop' to quit: ");
        fgets(str,MAX_LENGTH,stdin);
        if(str[strlen(str) - 1] == '\n') { // Removing the new line
            str[strlen(str) - 1] = '\0'; // Replacing it with \0
        }
        if (strcmp(str, "stop") == 0 || strcmp(str, "Stop") == 0 || strcmp(str, "STOP") == 0) {
            // Making sure the program stops even if the user writes 'stop' in all caps, or with a capital letter in the beginning
            running = 0;
        }if ( running != 0){
            size_t length = strlen(str); // Getting the size of the string
            printf("\nYour string is %zu characters long.\n",length);
        }
    }
    return 0;
}